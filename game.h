#pragma once

#include <stdbool.h>


struct game_t {
    bool is_running;
};

void game_init(struct game_t *game);
