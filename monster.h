#pragma once

#include <stdint.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "game.h"


struct monster_t {
    struct drawable_t *drawable;
};

void monster_init(struct monster_t *const monster, struct game_t *const game, const int8_t x, const int8_t y);

struct monster_t *monster_make(struct game_t *const game, const int8_t x, const int8_t y);

void monster_destroy(struct monster_t *monster);

void monster_act(struct monster_t *const monster, const map_t *const map);
