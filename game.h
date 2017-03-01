#pragma once

#include <stdbool.h>

#include "map.h"
#include "drawable.h"

struct actor_t;

struct game_t {
    bool is_running;

    map_t *maps[MAP_FLOOR_NUM];
    int8_t current_floor;
    TCOD_map_t tcod_map;

    struct drawable_t *drawable_list;
    struct actor_t *actor_list;
};

void game_init(struct game_t *game);

void game_fov_update(struct game_t *game, int8_t player_x, int8_t player_y);

bool game_in_fov(struct game_t *game, int8_t x, int8_t y);

map_t *game_get_current_map(const struct game_t *game);

void game_map_draw(const struct game_t *game, TCOD_console_t *console);

void game_drawable_list_draw(const struct game_t *game, TCOD_console_t *console);

void game_drawable_register(struct game_t *game, struct drawable_t *drawable);

void game_drawable_deregister(struct game_t *game, struct drawable_t *drawable);

void game_actor_list_act(struct game_t *game);

void game_actor_register(struct game_t *game, struct actor_t *actor);

void game_actor_deregister(struct game_t *game, struct actor_t *actor);

bool game_is_walkable(const struct game_t *game, int8_t x, int8_t y);

int8_t game_get_floor(struct game_t *game);

void game_increase_floor(struct game_t *game);

void game_decrease_floor(struct game_t *game);
