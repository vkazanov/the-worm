#pragma once

#include <stdint.h>

struct drawable_t {
    char c;

    int8_t floor, x, y;

    struct drawable_t *next;
};

struct drawable_t *drawable_make(const int8_t floor, const int8_t x, const int8_t y, const char c);

void drawable_init(struct drawable_t *const drawable, const int8_t floor, const int8_t x, const int8_t y, const char c);

void drawable_destroy(struct drawable_t *const drawable);
