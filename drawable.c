#include <stdlib.h>

#include "drawable.h"

struct drawable_t *drawable_make(const int8_t floor, const int8_t x, const int8_t y, const char c)
{
    struct drawable_t *drawable = malloc(sizeof *drawable);
    drawable_init(drawable, floor, x, y, c);
    return drawable;
}

void drawable_init(struct drawable_t *const drawable, const int8_t floor, const int8_t x, const int8_t y, const char c)
{
    drawable->c = c;
    drawable->floor = floor;
    drawable->x = x;
    drawable->y = y;
    drawable->is_walkable = true;
    drawable->next = NULL;
}

void drawable_destroy(struct drawable_t *const drawable)
{
    free(drawable);
}
