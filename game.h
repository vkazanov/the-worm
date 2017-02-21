#pragma once

#include <stdbool.h>

#include "map.h"


struct game_t {
    bool is_running;
    uint8_t current_floor;

    struct drawable_t *drawable_list[FLOOR_NUM];
};

struct drawable_t {
    char c;
    int8_t x, y;

    struct drawable_t *next, *prev;
};

void game_init(struct game_t *const game);

map_t *game_get_current_map(const struct game_t *const game);


void game_drawable_init(struct drawable_t *const drawable, const int8_t x, const int8_t y, const char c);

void game_drawable_register(struct game_t *const game, struct drawable_t *const drawable);

void game_drawable_list_draw(const struct game_t *const game, TCOD_console_t *const console);
