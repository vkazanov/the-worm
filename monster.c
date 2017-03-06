#include <stdlib.h>
#include <math.h>

#include "monster.h"

const char MONSTER_CHAR = 'M';

const int MONSTER_NOTICE_DISTANCE = 5;

void monster_init(struct monster_t *monster, struct game_t *game, const int8_t x, const int8_t y, const int8_t floor)
{
    struct drawable_t *drawable = malloc(sizeof *drawable);
    drawable_init(drawable, floor, x, y, MONSTER_CHAR, false, false);
    monster->drawable = drawable;
    game_drawable_register(game, drawable);

    monster->actor = actor_make(monster_act, monster, game);
    game_actor_register(game, monster->actor);
}

struct monster_t *monster_make(struct game_t *game, const int8_t x, const int8_t y, const int8_t floor)
{
    struct monster_t *monster = malloc(sizeof *monster);
    monster_init(monster, game, x, y, floor);
    return monster;
}

void monster_destroy(struct monster_t *monster)
{
    drawable_destroy(monster->drawable);
    free(monster);
}

static void monster_act_move_random(struct actor_t *actor)
{
    struct monster_t *monster = actor->parent;
    int delta_x = 0, delta_y = 0;
    delta_x = TCOD_random_get_int(NULL, -1, 1);
    delta_y = TCOD_random_get_int(NULL, -1, 1);

    int new_x = monster->drawable->x + delta_x;
    int new_y = monster->drawable->y + delta_y;
    if (game_is_walkable(actor->game, new_x, new_y)) {
        monster->drawable->x = new_x;
        monster->drawable->y = new_y;
    }

}

static void monster_act_move_to_target(struct actor_t *actor, struct drawable_t *target)
{
    struct monster_t *monster = actor->parent;
    struct drawable_t *this = monster->drawable;
    int8_t d_x = this->x - target->x;
    int8_t d_y = this->y - target->y;

    int delta_x = 0, delta_y = 0;
    if (d_x > 0) {
        delta_x = -1;
    } else if (d_x < 0) {
        delta_x = 1;
    }
    if (d_y > 0) {
        delta_y = -1;
    } else if (d_y < 0) {
        delta_y = 1;
    }

    int new_x = this->x + delta_x;
    int new_y = this->y + delta_y;
    if (game_is_walkable(actor->game, new_x, new_y)) {
        monster->drawable->x = new_x;
        monster->drawable->y = new_y;
    }

}

static struct drawable_t *monster_act_find_target(struct actor_t *actor)
{
    struct monster_t *monster = actor->parent;
    struct drawable_t *this = monster->drawable;

    if (!game_in_fov(actor->game, this->x, this->y))
        return NULL;

    for (struct drawable_t *drawable = actor->game->drawable_list; drawable; drawable = drawable->next) {
        if (drawable == this)
            continue;
        if (!drawable->is_attackable)
            continue;
        int8_t d_x = this->x - drawable->x;
        int8_t d_y = this->y - drawable->y;
        double distance = sqrt(pow(d_x, 2) + pow(d_y, 2));
        if (distance < MONSTER_NOTICE_DISTANCE)
            return drawable;
    }

    return NULL;
}

void monster_act(struct actor_t *actor)
{
    struct drawable_t *target = monster_act_find_target(actor);
    if (target) {
        monster_act_move_to_target(actor, target);
    } else {
        monster_act_move_random(actor);
    }
}
