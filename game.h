#pragma once

#include <stdbool.h>

#include "map.h"


struct game_t {
    bool is_running;
    uint8_t current_floor;
};

void game_init(struct game_t *const game);

map_t *game_get_current_map(const struct game_t *const game);
