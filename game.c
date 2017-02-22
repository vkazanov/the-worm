#include <stdlib.h>

#include "game.h"

void game_init(struct game_t *const game)
{
    game->is_running = true;
    game->current_floor = 0;
    for (size_t floor = 0; floor < FLOOR_NUM; floor++)
        game->drawable_list[floor] = NULL;
}

map_t *game_get_current_map(const struct game_t *const game)
{
    return maps[game->current_floor];
}


struct drawable_t *game_drawable_make(const int8_t x, const int8_t y, const char c)
{
    struct drawable_t *drawable = malloc(sizeof *drawable);
    game_drawable_init(drawable, x, y, c);
    return drawable;
}

void game_drawable_init(struct drawable_t *const drawable, const int8_t x, const int8_t y, const char c)
{
    drawable->c = c;
    drawable->x = x;
    drawable->y = y;
    drawable->next = NULL;
}

void game_drawable_destroy(struct drawable_t *const drawable)
{
    free(drawable);
}

void game_drawable_register(struct drawable_t *const drawable, struct game_t *const game)
{
    struct drawable_t *old_head = game->drawable_list[game->current_floor];
    drawable->next = old_head;
    game->drawable_list[game->current_floor] = drawable;
}

void game_drawable_deregister(struct drawable_t *const drawable, struct game_t *const game)
{
    for (size_t f = 0; f < FLOOR_NUM; f++)
        for (struct drawable_t *this = game->drawable_list[f], *prev = NULL ; this; prev = this, this = this->next) {
            if (this == drawable) {
                if (prev)
                    prev->next = this->next;
                else
                    game->drawable_list[f] = this->next;
            }
        }
}

void game_drawable_list_draw(const struct game_t *const game, TCOD_console_t *const console)
{
    for (struct drawable_t *drawable = game->drawable_list[game->current_floor]; drawable; drawable = drawable->next)
        TCOD_console_put_char(console, drawable->x, drawable->y, drawable->c, TCOD_BKGND_DEFAULT);
}
