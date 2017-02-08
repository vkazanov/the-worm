#pragma once

#include <stdint.h>


struct player_t {
    int8_t x;
    int8_t y;
};

void player_move_left(struct player_t *const player);


void player_move_right(struct player_t *const player);


void player_move_up(struct player_t *const player);


void player_move_down(struct player_t *const player);
