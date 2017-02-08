#include <stdbool.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "player.h"


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
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_right(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->x + 1;
    int8_t new_y = player->y;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_up(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->x;
    int8_t new_y = player->y - 1;
    return map_is_walkable(map, new_x, new_y);
}

bool player_can_move_down(const struct player_t *const player, const map_t *const map)
{
    int8_t new_x = player->x;
    int8_t new_y = player->y + 1;
    return map_is_walkable(map, new_x, new_y);
}

void player_draw(const struct player_t *const player)
{
    TCOD_console_put_char(NULL, player->x, player->y, '@', TCOD_BKGND_DEFAULT);
}
