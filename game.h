#pragma once

#include <stdbool.h>

#include "map.h"
#include "drawable.h"

struct actor_t;

struct game_t {
    bool is_running;
    int8_t current_floor;

    struct drawable_t *drawable_list;
    struct actor_t *actor_list;
};

void game_init(struct game_t *const game);

map_t *game_get_current_map(const struct game_t *const game);

void game_drawable_list_draw(const struct game_t *const game, TCOD_console_t *const console);

void game_drawable_register(struct game_t *const game, struct drawable_t *const drawable);

void game_drawable_deregister(struct game_t *const game, struct drawable_t *const drawable);

void game_actor_list_act(struct game_t *const game);

void game_actor_register(struct game_t *const game, struct actor_t *const actor);

void game_actor_deregister(struct game_t *const game, struct actor_t *const actor);

bool game_is_walkable(const struct game_t *const game, int8_t x, int8_t y);
