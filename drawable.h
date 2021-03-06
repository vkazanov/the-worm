#pragma once

#include <stdint.h>
#include <stdbool.h>

struct drawable_t;
typedef struct drawable_t drawable_t;

typedef void drawable_on_attack_function_t(drawable_t *drawable);

struct drawable_t {
    char c;

    int8_t floor, x, y;

    bool is_walkable;
    bool is_attackable;
    bool is_player;

    void *parent;
    drawable_on_attack_function_t *on_attack;

    drawable_t *next;
};

drawable_t *drawable_make(const int8_t floor, const int8_t x, const int8_t y, const char c, const bool is_walkable, const bool is_attackable, const bool is_player, void *parent, drawable_on_attack_function_t *on_attack);

void drawable_init(drawable_t *drawable, const int8_t floor, const int8_t x, const int8_t y, const char c, const bool is_walkable, const bool is_attackable, const bool is_player, void *parent, drawable_on_attack_function_t *on_attack);

void drawable_destroy(drawable_t *drawable);
