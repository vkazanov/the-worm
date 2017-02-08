#include "map.h"


map_t map1 = {
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
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, UP, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
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

map_t map2 = {
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
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, UP, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, DN, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},

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

map_t map3 = {
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
    {WL, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, DN, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, FR, WL},
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

map_t *maps[FLOOR_NUM] = {
    &map1,
    &map2,
    &map3,
};
