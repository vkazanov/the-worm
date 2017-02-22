#include <stdbool.h>
#include <stdlib.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "log.h"
#include "player.h"
#include "message.h"

const char HEAD_CHAR = '@';
const char BODY_CHAR = 'o';

static struct player_body_t *player_body_make(const char c, const int8_t x, const int8_t y);
static void player_body_destroy(struct player_body_t *body);
static void player_move_to(struct player_t *const player, const int8_t new_x, const int8_t new_y);
static void player_push_head(struct player_t *player, const int8_t new_x, const int8_t new_y);
static void player_pop_tail(struct player_t *player);

void player_init(struct player_t *const player, struct game_t *const game, const int8_t x, const int8_t y)
{
    player->head = player_body_make(HEAD_CHAR, x, y);
    game_drawable_register(game, player->head->drawable);
    player->do_increase_length = false;
    player->do_decrease_length = false;
    player->game = game;

}

void player_act(struct player_t *const player, struct game_t *const game, map_t *const map)
{
    TCOD_key_t key;
    TCOD_sys_wait_for_event(TCOD_EVENT_KEY_PRESS, &key, NULL, true);
    switch(key.vk) {
    case TCODK_UP:
        if (player_can_move_up(player, map))
            player_move_up(player);
        break;
    case TCODK_DOWN:
        if (player_can_move_down(player, map))
            player_move_down(player);
        break;
    case TCODK_LEFT:
        if (player_can_move_left(player, map))
            player_move_left(player);
        break;
    case TCODK_RIGHT:
        if (player_can_move_right(player, map))
            player_move_right(player);
        break;
    case TCODK_CHAR:
        if (key.c == 'q') {
            game->is_running = false;
            return;
        } else if (key.c == 'i') {
            player_increase_length(player);
            log_msg("%s","Length increased");
        } else if (key.c == 'd') {
            player_decrease_length(player);
            log_msg("%s","Length decreased");
        } else if (key.c == 'c') {
            message("A key pressed!");
        }
        break;
    default:
        break;
    }

    /* See if actions should be taken based upon those updates */
    if (player_can_move_higher(player, map)) {
        game->current_floor++;
        player_move_vertically(player);
        log_msg("%s","Moved higher");
    } else if (player_can_move_lower(player, map)) {
        game->current_floor--;
        player_move_vertically(player);
        log_msg("%s","Moved lower");
    } else if (player_can_quit(player, map)) {
        message("Game won!");
        game->is_running = false;
        return;
    } else if (player_can_pickup(player, map)) {
        player_pickup(player, map);
        log_msg("%s", "Object found!");
    }
}

void player_move_left(struct player_t *const player)
{
    player_move_to(player, player->head->drawable->x - 1, player->head->drawable->y);
}

void player_move_right(struct player_t *const player)
{
    player_move_to(player, player->head->drawable->x + 1, player->head->drawable->y);
}

void player_move_up(struct player_t *const player)
{
    player_move_to(player, player->head->drawable->x, player->head->drawable->y - 1);
}

void player_move_down(struct player_t *const player)
{
    player_move_to(player, player->head->drawable->x, player->head->drawable->y + 1);
}

void player_move_vertically(struct player_t *const player)
{
    player_move_to(player, player->head->drawable->x, player->head->drawable->y);
}


bool player_can_move_left(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->head->drawable->x - 1;
    int8_t new_y = player->head->drawable->y;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_right(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->head->drawable->x + 1;
    int8_t new_y = player->head->drawable->y;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_up(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->head->drawable->x;
    int8_t new_y = player->head->drawable->y - 1;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_down(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->head->drawable->x;
    int8_t new_y = player->head->drawable->y + 1;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_higher(const struct player_t *const player, const map_t *const map)
{
    return map_is_ladder_higher(map, player->head->drawable->x, player->head->drawable->y);
}

bool player_can_move_lower(const struct player_t *const player, const map_t *const map)
{
    return map_is_ladder_lower(map, player->head->drawable->x, player->head->drawable->y);
}

bool player_can_quit(const struct player_t *const player, const map_t *const map)
{
    return map_is_exit(map, player->head->drawable->x, player->head->drawable->y);
}

bool player_can_pickup(const struct player_t *const player, const map_t *const map)
{
    return map_has_obj(map, player->head->drawable->x, player->head->drawable->y);
}

void player_pickup(struct player_t *const player, map_t *const map)
{
    enum obj_type_t obj = map_get_obj(map, player->head->drawable->x, player->head->drawable->y);
    if (obj == FD) {
        player_increase_length(player);
        map_set_obj(map, player->head->drawable->x, player->head->drawable->y, EM);
    }
}

void player_increase_length(struct player_t *const player)
{
    player->do_increase_length = true;
}

void player_decrease_length(struct player_t *const player)
{
    player->do_decrease_length = true;
}

static struct player_body_t *player_body_make(const char c, const int8_t x, const int8_t y)
{
    struct player_body_t *body = malloc(sizeof(*body));
    body->drawable = game_drawable_make(x, y, c);
    body->prev = NULL;
    body->next = NULL;
    return body;
}

static void player_move_to(struct player_t *const player, const int8_t new_x, const int8_t new_y)
{
    player_push_head(player, new_x, new_y);

    if (player->do_increase_length) {
        player->do_increase_length = false;
    } else if (player->do_decrease_length) {
        player_pop_tail(player);
        player_pop_tail(player);
        player->do_decrease_length = false;
    } else {
        player_pop_tail(player);
    }
}

static void player_push_head(struct player_t *player, const int8_t new_x, const int8_t new_y)
{
    struct player_body_t *old_head = player->head;
    struct player_body_t *new_head = player_body_make(HEAD_CHAR, new_x, new_y);
    game_drawable_register(player->game, new_head->drawable);
    new_head->next = old_head;
    old_head->prev = new_head;
    old_head->drawable->c = BODY_CHAR;
    player->head = new_head;
}

static void player_pop_tail(struct player_t *player)
{
    struct player_body_t *tail;
    for (tail = player->head; tail->next; tail = tail->next);
    if (tail != player->head) {
        game_drawable_deregister(player->game, tail->drawable);
        player_body_destroy(tail);
    }
}

static void player_body_destroy(struct player_body_t *body)
{
    game_drawable_destroy(body->drawable);
    if (body->prev)
        body->prev->next = NULL;
    free(body);
}
