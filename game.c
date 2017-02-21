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

void game_drawable_init(struct drawable_t *const drawable, const int8_t x, const int8_t y, const char c)
{
    drawable->c = c;
    drawable->x = x;
    drawable->y = y;
    drawable->next = NULL;
    drawable->prev = NULL;
}

void game_drawable_register(struct game_t *const game, struct drawable_t *const drawable)
{
    drawable->next = game->drawable_list;
    if (game->drawable_list)
        game->drawable_list->prev = drawable;
    game->drawable_list = drawable;
}

void game_drawable_list_draw(const struct game_t *const game, TCOD_console_t *const console)
{
    for (struct drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next)
        TCOD_console_put_char(console, drawable->x, drawable->y, drawable->c, TCOD_BKGND_DEFAULT);
}
