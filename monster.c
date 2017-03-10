#include <stdlib.h>
#include <math.h>

#include "monster.h"

const char MONSTER_CHAR = 'M';

const int MONSTER_NOTICE_DISTANCE = 5.;

void monster_init(monster_t *monster, game_t *game, const int8_t x, const int8_t y, const int8_t floor)
{
    drawable_t *drawable = malloc(sizeof *drawable);
    drawable_init(drawable, floor, x, y, MONSTER_CHAR, false, true, false, NULL, NULL);
    monster->drawable = drawable;
    game_drawable_register(game, drawable);

    monster->actor = actor_make(monster_act, monster, game);
    game_actor_register(game, monster->actor);
}

monster_t *monster_make(game_t *game, const int8_t x, const int8_t y, const int8_t floor)
{
    monster_t *monster = malloc(sizeof *monster);
    monster_init(monster, game, x, y, floor);
    return monster;
}

void monster_destroy(monster_t *monster)
{
    drawable_destroy(monster->drawable);
    free(monster);
}

static void monster_act_move_random(actor_t *actor)
{
    monster_t *monster = actor->parent;
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

static void monster_act_move_to_target(actor_t *actor, drawable_t *target)
{
    monster_t *monster = actor->parent;
    drawable_t *this = monster->drawable;
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

static drawable_t *monster_act_find_target(actor_t *actor, int8_t *res_d_x, int8_t *res_d_y)
{
    monster_t *monster = actor->parent;
    drawable_t *this = monster->drawable;
    if (!game_in_fov(actor->game, this->x, this->y))
        return NULL;

    drawable_t *target = NULL;
    double target_distance = MONSTER_NOTICE_DISTANCE;

    game_t *game = actor->game;
    for (drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next) {
        if (drawable == this)
            continue;
        if (!drawable->is_player)
            continue;
        int8_t d_x = this->x - drawable->x;
        int8_t  d_y = this->y - drawable->y;

        double distance = sqrt(pow(d_x, 2) + pow(d_y, 2));
        if (distance <= target_distance) {
            target = drawable;
            target_distance = distance;
            *res_d_x = d_x;
            *res_d_y = d_y;
        }
    }

    return target;
}

static bool monster_act_can_attack(actor_t *actor, int8_t d_x, int8_t d_y)
{
    (void) actor;
    return abs(d_x) <= 1 && abs(d_y) <= 1;
}

static void monster_act_attack_target(actor_t *actor, drawable_t *target)
{
    (void) actor;
    if (target->on_attack)
        target->on_attack(target);
}

void monster_act(actor_t *actor)
{
    monster_t *monster = actor->parent;
    drawable_t *this = monster->drawable;
    if (!game_in_fov(actor->game, this->x, this->y))
        return;

    int8_t d_x = 0, d_y = 0;
    drawable_t *target = monster_act_find_target(actor, &d_x, &d_y);
    if (target && monster_act_can_attack(actor, d_x, d_y)) {
        monster_act_attack_target(actor, target);
    } else if (target) {
        monster_act_move_to_target(actor, target);
    } else {
        monster_act_move_random(actor);
    }
}
