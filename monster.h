#pragma once

#include <stdint.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "game.h"
#include "actor.h"


struct monster_t {
    struct drawable_t *drawable;
    struct actor_t *actor;
};

void monster_init(struct monster_t *const monster, struct game_t *const game, const int8_t x, const int8_t y, const int8_t floor);

struct monster_t *monster_make(struct game_t *const game, const int8_t x, const int8_t y, const int8_t floor);

void monster_destroy(struct monster_t *monster);

void monster_act(struct actor_t *const actor);
