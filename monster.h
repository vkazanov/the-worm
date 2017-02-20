#pragma once

#include <stdint.h>

#include <libtcod/libtcod.h>

#include "map.h"


struct monster_t {
    int8_t x, y;
};

void monster_init(struct monster_t *const monster, const int8_t x, const int8_t y);

struct monster_t *monster_make(const int8_t x, const int8_t y);

void monster_destroy(struct monster_t *monster);

void monster_draw(const struct monster_t *const monster, TCOD_console_t *console);

void monster_act(struct monster_t *const monster, const map_t *const map);
