#pragma once

#include <stdint.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "game.h"
#include "actor.h"


struct monster_t {
    drawable_t *drawable;
    actor_t *actor;
};
typedef struct monster_t monster_t;

void monster_init(monster_t *monster, game_t *game, const int8_t x, const int8_t y, const int8_t floor);

monster_t *monster_make(game_t *game, const int8_t x, const int8_t y, const int8_t floor);

void monster_destroy(monster_t *monster);

void monster_act(actor_t *actor);
