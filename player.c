#include <stdbool.h>
#include <stdlib.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "log.h"
#include "player.h"
#include "actor.h"
#include "message.h"

const char HEAD_CHAR = '@';
const char BODY_CHAR = 'o';

static struct player_body_t *player_body_make(const char c, const int8_t floor, const int8_t x, const int8_t y);
static void player_body_destroy(struct player_body_t *body);
static void player_move_to(struct player_t *player, const int8_t new_floor, const int8_t new_x, const int8_t new_y);
static void player_push_head(struct player_t *player, const int8_t floor, const int8_t new_x, const int8_t new_y);
static void player_pop_tail(struct player_t *player);

void player_init(struct player_t *player, struct game_t *game, const int8_t x, const int8_t y)
{
    player->head = player_body_make(HEAD_CHAR, game_get_floor(game), x, y);
    game_drawable_register(game, player->head->drawable);

    player->do_increase_length = false;
    player->do_decrease_length = false;

    player->game = game;
    player->actor = actor_make(player_act, player, game);
    game_actor_register(game, player->actor);
}

void player_act(struct actor_t *actor)
{
    struct player_t *player = actor->parent;
    struct game_t *game = actor->game;

    TCOD_key_t key;
    TCOD_sys_wait_for_event(TCOD_EVENT_KEY_PRESS, &key, NULL, true);
    switch(key.vk) {
    case TCODK_UP:
        if (player_can_move_up(player))
            player_move_up(player);
        break;
    case TCODK_DOWN:
        if (player_can_move_down(player))
            player_move_down(player);
        break;
    case TCODK_LEFT:
        if (player_can_move_left(player))
            player_move_left(player);
        break;
    case TCODK_RIGHT:
        if (player_can_move_right(player))
            player_move_right(player);
        break;
    case TCODK_CHAR:
        if (key.c == 'q') {
            game->is_running = false;
            return;
        } else if (key.c == 'i') {
            player->do_increase_length = true;
            log_msg("%s","Length increased");
        } else if (key.c == 'd') {
            player->do_decrease_length = true;
            log_msg("%s","Length decreased");
        } else if (key.c == 'c') {
            message("A key pressed!");
        }
        break;
    default:
        break;
    }

    /* See if actions should be taken based upon those updates */
    if (player_can_move_higher(player)) {
        game_increase_floor(game);
        player_move_vertically(player);
        log_msg("%s","Moved higher");
    } else if (player_can_move_lower(player)) {
        game_decrease_floor(game);
        player_move_vertically(player);
        log_msg("%s","Moved lower");
    } else if (player_can_quit(player)) {
        message("Game won!");
        game->is_running = false;
        return;
    } else if (player_can_pickup(player)) {
        player_pickup(player);
        log_msg("%s", "Object found!");
    }
}

void player_fov_update(struct player_t *player)
{
    struct drawable_t *head = player->head->drawable;
    game_fov_update(player->game, head->x, head->y);
}

void player_move_left(struct player_t *player)
{
    player_move_to(
        player,
        game_get_floor(player->game),
        player->head->drawable->x - 1,
        player->head->drawable->y
    );
}

void player_move_right(struct player_t *player)
{
    player_move_to(
        player,
        game_get_floor(player->game),
        player->head->drawable->x + 1,
        player->head->drawable->y
    );
}

void player_move_up(struct player_t *player)
{
    player_move_to(
        player,
        game_get_floor(player->game),
        player->head->drawable->x,
        player->head->drawable->y - 1
    );
}

void player_move_down(struct player_t *player)
{
    player_move_to(
        player,
        game_get_floor(player->game),
        player->head->drawable->x,
        player->head->drawable->y + 1
    );
}

void player_move_vertically(struct player_t *player)
{
    player_move_to(
        player,
        game_get_floor(player->game),
        player->head->drawable->x,
        player->head->drawable->y
    );
}


bool player_can_move_left(const struct player_t *player)
{
    int8_t new_x = player->head->drawable->x - 1;
    int8_t new_y = player->head->drawable->y;
    return game_is_walkable(player->game, new_x, new_y);
}

bool player_can_move_right(const struct player_t *player)
{
    int8_t new_x = player->head->drawable->x + 1;
    int8_t new_y = player->head->drawable->y;
    return game_is_walkable(player->game, new_x, new_y);
}

bool player_can_move_up(const struct player_t *player)
{
    int8_t new_x = player->head->drawable->x;
    int8_t new_y = player->head->drawable->y - 1;
    return game_is_walkable(player->game, new_x, new_y);
}

bool player_can_move_down(const struct player_t *player)
{
    int8_t new_x = player->head->drawable->x;
    int8_t new_y = player->head->drawable->y + 1;
    return game_is_walkable(player->game, new_x, new_y);
}

bool player_can_move_higher(const struct player_t *player)
{
    return map_is_ladder_higher(
        game_get_map(player->game),
        player->head->drawable->x,
        player->head->drawable->y
    );
}

bool player_can_move_lower(const struct player_t *player)
{
    return map_is_ladder_lower(
        game_get_map(player->game),
        player->head->drawable->x,
        player->head->drawable->y
    );
}

bool player_can_quit(const struct player_t *player)
{
    return map_is_exit(
        game_get_map(player->game),
        player->head->drawable->x,
        player->head->drawable->y
    );
}

bool player_can_pickup(const struct player_t *player)
{
    return map_has_obj(
        game_get_map(player->game),
        player->head->drawable->x,
        player->head->drawable->y
    );
}

void player_pickup(struct player_t *player)
{
    struct map_t *map = game_get_map(player->game);
    const int8_t x = player->head->drawable->x, y = player->head->drawable->y;
    enum obj_type_t obj = map_get_obj(
        map,
        x, y
    );
    if (obj == FD) {
        player->do_increase_length++;
        map_set_obj(
            map,
            x, y,
            EM
        );
    }
}

static struct player_body_t *player_body_make(const char c, const int8_t floor, const int8_t x, const int8_t y)
{
    struct player_body_t *body = malloc(sizeof(*body));
    body->drawable = drawable_make(floor, x, y, c, false, true, NULL);
    body->prev = NULL;
    body->next = NULL;
    return body;
}

static void player_move_to(struct player_t *player, const int8_t floor, const int8_t new_x, const int8_t new_y)
{
    player_push_head(player, floor, new_x, new_y);

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

static void player_push_head(struct player_t *player, const int8_t floor, const int8_t new_x, const int8_t new_y)
{
    struct player_body_t *old_head = player->head;
    struct player_body_t *new_head = player_body_make(HEAD_CHAR, floor, new_x, new_y);
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
    drawable_destroy(body->drawable);
    if (body->prev)
        body->prev->next = NULL;
    free(body);
}
