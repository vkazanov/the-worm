#pragma once

#include <stdbool.h>

#include "map.h"
#include "drawable.h"

struct actor_t;
typedef struct actor_t actor_t;

struct game_t {
    bool is_running;

    map_t map;
    TCOD_map_t tcod_map;

    drawable_t *drawable_list;
    actor_t *actor_list;
};
typedef struct game_t game_t;

void game_init(game_t *game);

void game_fov_update(game_t *game, int8_t player_x, int8_t player_y);

bool game_in_fov(game_t *game, int8_t x, int8_t y);

map_t *game_get_map(game_t *game);

void game_map_draw(game_t *game, TCOD_console_t *console);

void game_drawable_list_draw(const game_t *game, TCOD_console_t *console);

void game_drawable_register(game_t *game, drawable_t *drawable);

void game_drawable_deregister(game_t *game, drawable_t *drawable);

void game_actor_register(game_t *game, actor_t *actor);

void game_actor_deregister(game_t *game, actor_t *actor);

bool game_is_walkable(game_t *game, int8_t x, int8_t y);

drawable_t *game_find_attackable(game_t *game, int8_t new_x, int8_t new_y);

int8_t game_get_floor(const game_t *game);

void game_increase_floor(game_t *game);

void game_decrease_floor(game_t *game);
