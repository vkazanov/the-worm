#include <libtcod/libtcod.h>
#include <assert.h>
#include "map.h"

#define WL_EM {WL, EM}
#define FR_EM {FR, EM}
#define UP_EM {UP, EM}
#define DN_EM {DN, EM}
#define EX_EM {EX, EM}

#define FR_FD {FR, FD}

map_t map1 = {
    {WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_FD, FR_FD, FR_FD, FR_EM, FR_FD, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, UP_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM}
};

map_t map2 = {
    {WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, UP_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, DN_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM}
};

map_t map3 = {
    {WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, DN_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, EX_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM, WL_EM}
};

bool map_is_walkable(const map_t *map, int8_t x, int8_t y) {
    if (x < 0 || x >= MAP_WIDTH)
        return false;
    if (y < 0 || y >= MAP_HEIGHT)
        return false;
    if ((*map)[y][x].tile_type == WL)
        return false;
    return true;
}

bool map_is_ladder_higher(const map_t *map, int8_t x, int8_t y)
{
    return (*map)[y][x].tile_type == UP;
}

bool map_is_ladder_lower(const map_t *map, int8_t x, int8_t y)
{
    return (*map)[y][x].tile_type == DN;
}

bool map_is_exit(const map_t *map, int8_t x, int8_t y)
{
    return (*map)[y][x].tile_type == EX;
}

bool map_has_obj(const map_t *map, int8_t x, int8_t y)
{
    return (*map)[y][x].obj_type != EM;
}

bool map_get_obj(const map_t *map, int8_t x, int8_t y)
{
    return (*map)[y][x].obj_type;
}

void map_set_obj(map_t *map, int8_t x, int8_t y, const enum obj_type_t obj)
{
    (*map)[y][x].obj_type = obj;
}

void map_draw(map_t *map, TCOD_console_t *console)
{
    for (int x = 0; x < MAP_WIDTH; x++)
        for (int y = 0; y < MAP_HEIGHT; y++) {
            char c;
            /* Immutable map layer */
            switch((*map)[y][x].tile_type) {
            case WL:
                c = '#';
                break;
            case FR:
                c = '.';
                break;
            case UP:
                c = '>';
                break;
            case DN:
                c = '<';
                break;
            case EX:
                c = '^';
                break;
            default:
                assert(false);
                break;
            }

            /* Object layer */
            switch((*map)[y][x].obj_type) {
            case FD:
                c = ';';
                break;
            default:
                break;
            }
            TCOD_console_put_char(console, x, y, c, TCOD_BKGND_DEFAULT);
        }
}
