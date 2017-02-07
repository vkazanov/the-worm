#pragma once


#define MAP_WIDTH 40
#define MAP_HEIGHT 25

enum tile_t {
    /* FLoor */
    FR,
    /* Wall */
    WL,
    /* Ladder up */
    UP,
    /* Ladder down */
    DN,
};

const enum tile_t map[MAP_HEIGHT][MAP_WIDTH] = {
    {WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},

    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},

    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, DN, UP, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},

    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},

    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL, WL}
};
