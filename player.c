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
