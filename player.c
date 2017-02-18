#include <stdbool.h>
#include <stdlib.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "log.h"
#include "player.h"
#include "message.h"

const char HEAD_CHAR = '@';
const char BODY_CHAR = 'o';

static struct player_body_t *player_body_make(const int8_t x, const int8_t y);
static void player_body_destroy(struct player_body_t *body);
static void player_move_to(struct player_t *const player, const int8_t new_x, const int8_t new_y);
static void player_push_head(struct player_t *player, const int8_t new_x, const int8_t new_y);
static void player_pop_tail(struct player_t *player);

void player_init(struct player_t *const player, const int8_t x, const int8_t y)
{
    player->head = player_body_make(x, y);
}

bool player_act(struct player_t *const player, const map_t *const map)
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
        if (key.c == 'q')
            return false;
        else if (key.c == 'i') {
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

    return true;
}

void player_hide_tail(struct player_t *const player)
{
    for (struct player_body_t *tail = player->head->next; tail; tail = tail->next)
        tail->is_hidden = true;
}

void player_move_left(struct player_t *const player)
{
    player_move_to(player, player->head->x - 1, player->head->y);
}

void player_move_right(struct player_t *const player)
{
    player_move_to(player, player->head->x + 1, player->head->y);
}

void player_move_up(struct player_t *const player)
{
    player_move_to(player, player->head->x, player->head->y - 1);
}

void player_move_down(struct player_t *const player)
{
    player_move_to(player, player->head->x, player->head->y + 1);
}

bool player_can_move_left(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->head->x - 1;
    int8_t new_y = player->head->y;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_right(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->head->x + 1;
    int8_t new_y = player->head->y;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_up(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->head->x;
    int8_t new_y = player->head->y - 1;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_down(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->head->x;
    int8_t new_y = player->head->y + 1;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_higher(const struct player_t *const player, const map_t *const map)
{
    return map_is_ladder_higher(map, player->head->x, player->head->y);
}

bool player_can_move_lower(const struct player_t *const player, const map_t *const map)
{
    return map_is_ladder_lower(map, player->head->x, player->head->y);
}

bool player_can_quit(const struct player_t *const player, const map_t *const map)
{
    return map_is_exit(map, player->head->x, player->head->y);
}

bool player_can_pickup(const struct player_t *const player, const map_t *const map)
{
    return map_has_obj(map, player->head->x, player->head->y);
}

void player_pickup(struct player_t *const player, map_t *const map)
{
    enum obj_type_t obj = map_get_obj(map, player->head->x, player->head->y);
    if (obj == FD) {
        player_increase_length(player);
        map_set_obj(map, player->head->x, player->head->y, EM);
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

void player_draw(const struct player_t *const player, TCOD_console_t *console)
{
    struct player_body_t *body = player->head;
    TCOD_console_put_char(console, body->x, body->y, HEAD_CHAR, TCOD_BKGND_DEFAULT);
    for (body = body->next; body && !body->is_hidden; body = body->next)
        TCOD_console_put_char(console, body->x, body->y, BODY_CHAR, TCOD_BKGND_DEFAULT);
}

static struct player_body_t *player_body_make(const int8_t x, const int8_t y)
{
    struct player_body_t *body = malloc(sizeof(*body));
    body->x = x;
    body->y = y;
    body->is_hidden = false;
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
    struct player_body_t *new_head = player_body_make(new_x, new_y);
    new_head->next = old_head;
    old_head->prev = new_head;
    player->head = new_head;
}

static void player_pop_tail(struct player_t *player)
{
    struct player_body_t *tail;
    for (tail = player->head; tail->next; tail = tail->next);
    if (tail != player->head)
        player_body_destroy(tail);
}

static void player_body_destroy(struct player_body_t *body)
{
    body->prev->next = NULL;
    free(body);
}
