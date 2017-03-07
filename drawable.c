#include <stdlib.h>

#include "drawable.h"

struct drawable_t *drawable_make(const int8_t floor, const int8_t x, const int8_t y, const char c, const bool is_walkable, const bool is_attackable, const drawable_on_attack_function_t *on_attack)
{
    struct drawable_t *drawable = malloc(sizeof *drawable);
    drawable_init(drawable, floor, x, y, c, is_walkable, is_attackable, on_attack);
    return drawable;
}

void drawable_init(struct drawable_t *drawable, const int8_t floor, const int8_t x, const int8_t y, const char c, const bool is_walkable, const bool is_attackable, const drawable_on_attack_function_t *on_attack)
{
    drawable->c = c;
    drawable->floor = floor;
    drawable->x = x;
    drawable->y = y;
    drawable->is_walkable = is_walkable;
    drawable->is_attackable = is_attackable;
    drawable->next = NULL;
    drawable->on_attack = on_attack;
}

void drawable_destroy(struct drawable_t *drawable)
{
    free(drawable);
}
