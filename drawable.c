#include <stdlib.h>

#include "drawable.h"

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
