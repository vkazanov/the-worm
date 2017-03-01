#pragma once

#include <stdbool.h>
#include <stdint.h>

#include <libtcod/libtcod.h>

#define MAP_FLOOR_NUM 3
#define MAP_WIDTH 40
#define MAP_HEIGHT 25

enum obj_type_t {
        /* Empty */
        EM,
        /* Food */
        FD
};

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

    enum obj_type_t obj_type;
};

typedef struct tile_t grid_t[MAP_HEIGHT][MAP_WIDTH];

struct map_t {
    int8_t current_floor;
    grid_t *grid[MAP_FLOOR_NUM];
};

void map_init(struct map_t *map);

bool map_is_walkable(const struct map_t *map, int8_t x, int8_t y);

bool map_is_transparent(const struct map_t *map, int8_t x, int8_t y);

bool map_is_ladder_higher(const struct map_t *map, int8_t x, int8_t y);

bool map_is_ladder_lower(const struct map_t *map, int8_t x, int8_t y);

bool map_is_exit(const struct map_t *map, int8_t x, int8_t y);

bool map_has_obj(const struct map_t *map, int8_t x, int8_t y);

bool map_get_obj(const struct map_t *map, int8_t x, int8_t y);

void map_set_obj(struct map_t *map, int8_t x, int8_t y, enum obj_type_t obj);


void map_draw(struct map_t *map, TCOD_map_t tcod_map, TCOD_console_t *console);
