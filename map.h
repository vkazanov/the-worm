#pragma once

#include <stdbool.h>
#include <stdint.h>

#include <libtcod/libtcod.h>

#define FLOOR_NUM 3
#define MAP_WIDTH 40
#define MAP_HEIGHT 25

struct tile_t {
    enum {
        /* FLoor */
        FR,
        /* Wall */
        WL,
        /* Ladder up */
        UP,
        /* Ladder down */
        DN,
        /* Dungeon exit */
        EX,
    } tile_type;
    enum {
        /* Empty */
        EM,
        /* Food */
        FD,
    } obj_type;
};

typedef struct tile_t map_t[MAP_HEIGHT][MAP_WIDTH];

extern map_t *maps[FLOOR_NUM];


bool map_is_walkable(const map_t *const map, int8_t x, int8_t y);

bool map_is_ladder_higher(const map_t *const map, int8_t x, int8_t y);

bool map_is_ladder_lower(const map_t *const map, int8_t x, int8_t y);

bool map_is_exit(const map_t *const map, int8_t x, int8_t y);

bool map_has_obj(const map_t *const map, int8_t x, int8_t y);


void map_draw(map_t *map, TCOD_console_t *console);
