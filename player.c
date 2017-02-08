#include <stdbool.h>

#include <libtcod/libtcod.h>

#include "player.h"


static bool can_move_to(map_t *map, int8_t new_x, int8_t new_y)
{
    if (new_x < 0 || new_x >= MAP_WIDTH)
        return false;
    if (new_y < 0 || new_y >= MAP_WIDTH)
        return false;
    if ((*map)[new_y][new_x] == WL)
        return false;
    return true;
}

void player_move_left(struct player_t *const player)
{
    player->x--;
}

void player_move_right(struct player_t *const player)
{
    player->x++;
}

void player_move_up(struct player_t *const player)
{
    player->y--;
}

void player_move_down(struct player_t *const player)
{
    player->y++;
}

bool player_can_move_left(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->x - 1;
    int8_t new_y = player->y;
    return can_move_to(map, new_y, new_x);
}

bool player_can_move_right(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->x + 1;
    int8_t new_y = player->y;
    return can_move_to(map, new_y, new_x);
}

bool player_can_move_up(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->x;
    int8_t new_y = player->y - 1;
    return can_move_to(map, new_y, new_x);
}

bool player_can_move_down(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->x;
    int8_t new_y = player->y + 1;
    return can_move_to(map, new_y, new_x);
}


void player_draw(const struct player_t *const player)
{
    TCOD_console_put_char(NULL, player->x, player->y, '@', TCOD_BKGND_DEFAULT);
}
