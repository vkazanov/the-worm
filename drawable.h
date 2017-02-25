#pragma once

#include <stdint.h>
#include <stdbool.h>

struct drawable_t {
    char c;

    int8_t floor, x, y;

    bool is_walkable;

    struct drawable_t *next;
};

struct drawable_t *drawable_make(const int8_t floor, const int8_t x, const int8_t y, const char c, const bool is_walkable);

void drawable_init(struct drawable_t *drawable, const int8_t floor, const int8_t x, const int8_t y, const char c, const bool is_walkable);

void drawable_destroy(struct drawable_t *drawable);
