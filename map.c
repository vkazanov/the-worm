#include <libtcod/libtcod.h>
#include <assert.h>
#include "map.h"

#define WL_EM {WL, EM}
#define FR_EM {FR, EM}
#define UP_EM {UP, EM}
#define DN_EM {DN, EM}
#define EX_EM {EX, EM}

#define FR_FD {FR, FD}

grid_t grid1 = {
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

    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, UP_EM, FR_EM, FR_EM, FR_EM, WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},
    {WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, FR_EM, WL_EM},

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

grid_t grid2 = {
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

grid_t grid3 = {
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

void map_init(struct map_t *map)
{
    map->current_floor = 0;
    map->grid[0] = &grid1;
    map->grid[1] = &grid2;
    map->grid[2] = &grid3;

}

static grid_t *map_get_grid(const struct map_t *map)
{
    return map->grid[map->current_floor];
}

static struct tile_t *map_get_tile(const struct map_t *map, int8_t x, int8_t y)
{
    return map_get_grid(map)[y][x];
}

bool map_is_walkable(const struct map_t *map, int8_t x, int8_t y) {
    if (x < 0 || x >= MAP_WIDTH)
        return false;
    if (y < 0 || y >= MAP_HEIGHT)
        return false;
    return map_get_tile(map, x, y)->tile_type != WL;
}


bool map_is_transparent(const struct map_t *map, int8_t x, int8_t y)
{
    return map_get_tile(map, x, y)->tile_type != WL;
}


bool map_is_ladder_higher(const struct map_t *map, int8_t x, int8_t y)
{
    return map_get_tile(map, x, y)->tile_type == UP;
}

bool map_is_ladder_lower(const struct map_t *map, int8_t x, int8_t y)
{
    return map_get_tile(map, x, y)->tile_type == DN;
}

bool map_is_exit(const struct map_t *map, int8_t x, int8_t y)
{
    return map_get_tile(map, x, y)->tile_type == EX;
}

bool map_has_obj(const struct map_t *map, int8_t x, int8_t y)
{
    return map_get_tile(map, x, y)->obj_type != EM;
}

bool map_get_obj(const struct map_t *map, int8_t x, int8_t y)
{
    return map_get_tile(map, x, y)->obj_type;
}

void map_set_obj(struct map_t *map, int8_t x, int8_t y, const enum obj_type_t obj)
{
    map_get_tile(map, x, y)->obj_type = obj;
}

void map_draw(struct map_t *map, TCOD_map_t tcod_map, TCOD_console_t *console)
{
    for (int x = 0; x < MAP_WIDTH; x++)
        for (int y = 0; y < MAP_HEIGHT; y++) {
            if (!TCOD_map_is_in_fov(tcod_map, x, y))
                continue;

            char c;
            /* Immutable map layer */
            switch ((*map_get_grid(map))[y][x].tile_type) {
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
            switch((*map_get_grid(map))[y][x].obj_type) {
            case FD:
                c = ';';
                break;
            default:
                break;
            }
            TCOD_console_put_char(console, x, y, c, TCOD_BKGND_DEFAULT);
        }
}
