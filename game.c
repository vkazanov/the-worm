#include "game.h"

void game_init(struct game_t *game)
{
    game->is_running = true;
    game->current_floor = 0;
}

map_t *game_get_current_map(const struct game_t *const game)
{
    return maps[game->current_floor];
}
