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
typedef enum obj_type_t obj_type_t;

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
typedef struct tile_t tile_t;

typedef tile_t grid_t[MAP_HEIGHT][MAP_WIDTH];

struct map_t {
    int8_t current_floor;
    grid_t *grid[MAP_FLOOR_NUM];
};
typedef struct map_t map_t;

void map_init(map_t *map);

bool map_is_walkable(const map_t *map, int8_t x, int8_t y);

bool map_is_transparent(const map_t *map, int8_t x, int8_t y);

bool map_is_ladder_higher(const map_t *map, int8_t x, int8_t y);

bool map_is_ladder_lower(const map_t *map, int8_t x, int8_t y);

bool map_is_exit(const map_t *map, int8_t x, int8_t y);

bool map_has_obj(const map_t *map, int8_t x, int8_t y);

bool map_get_obj(const map_t *map, int8_t x, int8_t y);

void map_set_obj(map_t *map, int8_t x, int8_t y, obj_type_t obj);


void map_draw(map_t *map, TCOD_map_t tcod_map, TCOD_console_t *console);
