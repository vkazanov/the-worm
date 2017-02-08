#pragma once


#define FLOOR_NUM 3
#define MAP_WIDTH 40
#define MAP_HEIGHT 25

enum tile_t {
    /* FLoor */
    FR,
    /* Wall */
    WL,
    /* Ladder up */
    UP,
    /* Ladder down */
    DN,
};

typedef const enum tile_t map_t[MAP_HEIGHT][MAP_WIDTH];

extern map_t *maps[FLOOR_NUM];

void map_draw(map_t *map);
