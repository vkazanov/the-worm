#include <stdbool.h>
#include <stdlib.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "player.h"

static struct player_body_t *player_body_make(const int8_t x, const int8_t y);
static void player_body_destroy(struct player_body_t *body);
static void player_move_to(struct player_t *const player, const int8_t new_x, const int8_t new_y);
static void player_push_head(struct player_t *player, const int8_t new_x, const int8_t new_y);
static void player_pop_tail(struct player_t *player);

void player_init(struct player_t *const player, const int8_t x, const int8_t y)
{
    player->head = player_body_make(x, y);
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
    char c = (*map)[player->head->y][player->head->x];
    return c == UP;
}

bool player_can_move_lower(const struct player_t *const player, const map_t *const map)
{
    char c = (*map)[player->head->y][player->head->x];
    return c == DN;
}

void player_increase_length(struct player_t *const player)
{
    player->do_increase_length = true;
}

void player_decrease_length(struct player_t *const player)
{
    player->do_decrease_length = true;
}

void player_draw(const struct player_t *const player)
{
    struct player_body_t *body = player->head;
    TCOD_console_put_char(NULL, body->x, body->y, '@', TCOD_BKGND_DEFAULT);
    for (body = body->next; body && !body->is_hidden; body = body->next)
        TCOD_console_put_char(NULL, body->x, body->y, 'o', TCOD_BKGND_DEFAULT);
}

static struct player_body_t *player_body_make(const int8_t x, const int8_t y)
{
    struct player_body_t *body = malloc(sizeof(struct player_body_t));
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

    if (player->do_increase_length)
        player->do_increase_length = false;
    else if (player->do_decrease_length) {
        player_pop_tail(player);
        player_pop_tail(player);
        player->do_decrease_length = false;
    } else
        player_pop_tail(player);
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
