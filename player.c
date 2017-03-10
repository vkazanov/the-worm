#include <stdbool.h>
#include <assert.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "log.h"
#include "player.h"
#include "actor.h"
#include "message.h"
#include "utils.h"

const char HEAD_CHAR = '@';
const char HEAD_DAMAGED_CHAR = 'Q';
const char BODY_CHAR = 'O';
const char BODY_DAMAGED_CHAR = 'o';

static player_body_t *player_body_make(player_t *player, const char c, const int8_t floor, const int8_t x, const int8_t y);
static void player_body_destroy(player_body_t *body);
static void player_move_to(player_t *player, const int8_t new_floor, const int8_t new_x, const int8_t new_y);
static int8_t player_x(player_t *player);
static int8_t player_y(player_t *player);

void player_init(player_t *player, game_t *game, const int8_t x, const int8_t y)
{
    player->head = player_body_make(player, HEAD_CHAR, game_get_floor(game), x, y);
    game_drawable_register(game, player->head->drawable);

    player->do_increase_length = false;
    player->do_decrease_length = false;

    player->game = game;
    player->actor = actor_make(player_act, player, game);
    game_actor_register(game, player->actor);
}

void player_act(actor_t *actor)
{
    player_t *player = actor->parent;
    game_t *game = actor->game;
    map_t *map = game_get_map(game);

    TCOD_key_t key;
    int8_t new_x = player_x(player), new_y = player_y(player);
    int8_t floor = game_get_floor(game);
    bool do_move = false;

    /* Read the input */
readkey:
    TCOD_sys_wait_for_event(TCOD_EVENT_KEY_PRESS, &key, NULL, true);
    switch(key.vk) {
    case TCODK_UP:
        new_y -= 1;
        do_move = true;
        break;
    case TCODK_DOWN:
        new_y += 1;
        do_move = true;
        break;
    case TCODK_LEFT:
        new_x -= 1;
        do_move = true;
        break;
    case TCODK_RIGHT:
        new_x += 1;
        do_move = true;
        break;
    case TCODK_CHAR:
        if (key.c == 'q') {
            game->is_running = false;
        } else if (key.c == 'i') {
            player->do_increase_length = true;
            log_msg("%s","Length increased");
        } else if (key.c == 'd') {
            player->do_decrease_length = true;
            log_msg("%s","Length decreased");
        } else if (key.c == 'z') {
            log_msg("%s","Skip a step");
        } else {
            goto readkey;
        }
        break;
    default:
        break;
    }

    if (!do_move)
        return;

    /* If input is reasonable - act */
    drawable_t *attackable = game_find_attackable(game, new_x, new_y);
    if (attackable && attackable->on_attack) {
        log_msg("%s", "Attacking!");
        attackable->on_attack(attackable);
    } else if (game_is_walkable(game, new_x, new_y)) {
        player_move_to(player, floor, new_x, new_y);
        if (map_is_ladder_higher(map, new_x, new_y)) {
            game_increase_floor(game);
            player_move_to(player, game_get_floor(game), new_x, new_y);
            log_msg("%s","Moved higher");
        } else if (map_is_ladder_lower(map, new_x, new_y)) {
            game_decrease_floor(game);
            player_move_to(player, game_get_floor(game), new_x, new_y);
            log_msg("%s","Moved lower");
        } else if (map_is_exit(map, new_x, new_y)) {
            message("Game won!");
            game->is_running = false;
        } else if (map_has_obj(map, new_x, new_y)) {
            player_pickup(player);
            log_msg("%s", "Object found!");
        }
    }
}

void player_fov_update(player_t *player)
{
    drawable_t *head = player->head->drawable;
    game_fov_update(player->game, head->x, head->y);
}

void player_pickup(player_t *player)
{
    map_t *map = game_get_map(player->game);
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

static void player_body_drawable_on_attack(drawable_t *body_drawable)
{
    player_body_t *body = body_drawable->parent;
    player_t *player = body->player;

    if (body == player->head && body_drawable->c == HEAD_CHAR) {
        /* Damage the head */
        body_drawable->c = HEAD_DAMAGED_CHAR;
    } else if (body == player->head && body_drawable->c == HEAD_DAMAGED_CHAR) {
        /* Die */
        message("Game lost!");
        player->game->is_running = false;
    } else if (body != player->head && body_drawable->c == BODY_CHAR) {
        /* Damage the body */
        body_drawable->c = BODY_DAMAGED_CHAR;
    } else if (body != player->head && body_drawable->c == BODY_DAMAGED_CHAR) {
        /* Cut the tail */
        for (player_body_t *this = body; this; this = this->next) {
            game_drawable_deregister(player->game, this->drawable);
            player_body_destroy(this);
        }
    } else {
        assert(false);
    }
}

static player_body_t *player_body_make(player_t *player, const char c, const int8_t floor, const int8_t x, const int8_t y)
{
    player_body_t *body = MALLOC(sizeof(*body));
    body->drawable = drawable_make(floor, x, y, c, false, false, true, body, player_body_drawable_on_attack);
    body->prev = NULL;
    body->next = NULL;
    body->player = player;
    return body;
}

static void player_pop_tail(player_t *player)
{
    player_body_t *tail;
    for (tail = player->head; tail->next; tail = tail->next);
    if (tail != player->head) {
        game_drawable_deregister(player->game, tail->drawable);
        player_body_destroy(tail);
    }
}

static void player_push_tail(player_t *player, const int8_t floor, const int8_t new_x, const int8_t new_y)
{
    player_body_t *tail;
    for (tail = player->head; tail->next; tail = tail->next);
    player_body_t *new_body = player_body_make(player, BODY_CHAR, floor, new_x, new_y);
    game_drawable_register(player->game, new_body->drawable);
    tail->next = new_body;
    new_body->prev = tail;
}

static void player_move_to(player_t *player, const int8_t new_floor, const int8_t new_x, const int8_t new_y)
{
    int8_t next_x = new_x, next_y = new_y, next_floor = new_floor;
    if (player->do_decrease_length) {
        player_pop_tail(player);
        player->do_decrease_length = false;
    }
    for (player_body_t *this = player->head; this; this = this->next) {
        int8_t old_x = this->drawable->x;
        int8_t old_y = this->drawable->y;
        int8_t old_floor = this->drawable->floor;
        this->drawable->x = next_x;
        this->drawable->y = next_y;
        this->drawable->floor = next_floor;
        next_x = old_x;
        next_y = old_y;
        next_floor = old_floor;
    }
    if (player->do_increase_length) {
        player_push_tail(player, next_floor, next_x, next_y);
        player->do_increase_length = false;
    }
}

static void player_body_destroy(player_body_t *body)
{
    drawable_destroy(body->drawable);
    if (body->prev)
        body->prev->next = NULL;
    if (body->next)
        body->next->prev = NULL;
    FREE(body);
}

static int8_t player_x(player_t *player)
{
    return player->head->drawable->x;
}

static int8_t player_y(player_t *player)
{
    return player->head->drawable->y;
}
