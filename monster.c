#include <stdlib.h>

#include "monster.h"

const char MONSTER_CHAR = 'M';

void monster_init(struct monster_t *const monster, const int8_t x, const int8_t y)
{
    monster->x = x;
    monster->y = y;
}

struct monster_t *monster_make(const int8_t x, const int8_t y)
{
    struct monster_t *monster = malloc(sizeof *monster);
    monster_init(monster, x, y);
    return monster;
}

void monster_destroy(struct monster_t *monster)
{
    free(monster);
}

void monster_draw(const struct monster_t *const monster, TCOD_console_t *console)
{
    TCOD_console_put_char(console, monster->x, monster->y, MONSTER_CHAR, TCOD_BKGND_DEFAULT);
}

void monster_act(struct monster_t *const monster, const map_t *const map)
{
    (void) monster, (void) map;
    /* TODO: a noop for now */
}
