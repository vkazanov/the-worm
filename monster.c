#include <stdlib.h>

#include "monster.h"

const char MONSTER_CHAR = 'M';

void monster_init(struct monster_t *const monster, struct game_t *const game, const int8_t x, const int8_t y)
{
    struct drawable_t *drawable = malloc(sizeof *drawable);
    drawable_init(drawable, game->current_floor, x, y, MONSTER_CHAR, false);
    monster->drawable = drawable;
    game_drawable_register(game, drawable);

    monster->actor = actor_make(monster_act, monster, game);
    game_actor_register(game, monster->actor);
}

struct monster_t *monster_make(struct game_t *const game, const int8_t x, const int8_t y)
{
    struct monster_t *monster = malloc(sizeof *monster);
    monster_init(monster, game, x, y);
    return monster;
}

void monster_destroy(struct monster_t *monster)
{
    drawable_destroy(monster->drawable);
    free(monster);
}

void monster_act(struct actor_t *const actor)
{
    struct monster_t *const monster = actor->parent;

    int delta_x = TCOD_random_get_int(NULL, -1, 1);
    int delta_y = TCOD_random_get_int(NULL, -1, 1);
    int new_x = monster->drawable->x + delta_x;
    int new_y = monster->drawable->y + delta_y;
    if (game_is_walkable(actor->game, new_x, new_y)) {
        monster->drawable->x = new_x;
        monster->drawable->y = new_y;
    }
}
