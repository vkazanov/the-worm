#include <stdlib.h>

#include "drawable.h"

struct drawable_t *drawable_make(const int8_t floor, const int8_t x, const int8_t y, const char c, const bool is_walkable)
{
    struct drawable_t *drawable = malloc(sizeof *drawable);
    drawable_init(drawable, floor, x, y, c, is_walkable);
    return drawable;
}

void drawable_init(struct drawable_t *const drawable, const int8_t floor, const int8_t x, const int8_t y, const char c, const bool is_walkable)
{
    drawable->c = c;
    drawable->floor = floor;
    drawable->x = x;
    drawable->y = y;
    drawable->is_walkable = is_walkable;
    drawable->next = NULL;
}

void drawable_destroy(struct drawable_t *const drawable)
{
    free(drawable);
}
