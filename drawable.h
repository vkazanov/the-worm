#pragma once

#include <stdint.h>

struct drawable_t {
    char c;
    int8_t x, y;

    struct drawable_t *next;
};

struct drawable_t *game_drawable_make(const int8_t x, const int8_t y, const char c);

void game_drawable_init(struct drawable_t *const drawable, const int8_t x, const int8_t y, const char c);

void game_drawable_destroy(struct drawable_t *const drawable);
