#include <stdlib.h>

#include "monster.h"

const char MONSTER_CHAR = 'M';

void monster_init(struct monster_t *const monster, struct game_t *const game, const int8_t x, const int8_t y)
{
    struct drawable_t *drawable = malloc(sizeof *drawable);
    game_drawable_init(drawable, x, y, MONSTER_CHAR);
    monster->drawable = drawable;
    game_drawable_register(drawable, game);
}

struct monster_t *monster_make(struct game_t *const game, const int8_t x, const int8_t y)
{
    struct monster_t *monster = malloc(sizeof *monster);
    monster_init(monster, game, x, y);
    return monster;
}

void monster_destroy(struct monster_t *monster)
{
    free(monster);
}

void monster_act(struct monster_t *const monster, const map_t *const map)
{
    (void) monster, (void) map;
    /* TODO: a noop for now */
}
