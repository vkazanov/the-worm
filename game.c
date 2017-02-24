#include <stdlib.h>

#include "game.h"
#include "actor.h"

void game_init(struct game_t *const game)
{
    game->is_running = true;
    game->current_floor = 0;
    game->drawable_list = NULL;
    game->actor_list = NULL;
}

map_t *game_get_current_map(const struct game_t *const game)
{
    return maps[game->current_floor];
}

void game_drawable_register(struct game_t *const game, struct drawable_t *const drawable)
{
    struct drawable_t *old_head = game->drawable_list;
    drawable->next = old_head;
    game->drawable_list = drawable;
}

void game_drawable_deregister(struct game_t *const game, struct drawable_t *const drawable)
{
    for (struct drawable_t *this = game->drawable_list, *prev = NULL ; this; prev = this, this = this->next) {
        if (this == drawable) {
            if (prev)
                prev->next = this->next;
            else
                game->drawable_list = this->next;
        }
    }
}

void game_actor_list_act(struct game_t *const game)
{
    for (struct actor_t *actor = game->actor_list; actor; actor = actor->next)
        actor->act(actor);
}

void game_actor_register(struct game_t *const game, struct actor_t *const actor)
{
    struct actor_t *old_head = game->actor_list;
    actor->next = old_head;
    game->actor_list = actor;
}

void game_actor_deregister(struct game_t *const game, struct actor_t *const actor)
{
    for (struct actor_t *this = game->actor_list, *prev = NULL ; this; prev = this, this = this->next) {
        if (this == actor) {
            if (prev)
                prev->next = this->next;
            else
                game->actor_list = this->next;
        }
    }
}

void game_drawable_list_draw(const struct game_t *const game, TCOD_console_t *const console)
{
    for (struct drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next)
        if (game->current_floor == drawable->floor)
            TCOD_console_put_char(console, drawable->x, drawable->y, drawable->c, TCOD_BKGND_DEFAULT);
}

bool game_is_walkable(const struct game_t *const game, const int8_t x, const int8_t y)
{
    for (struct drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next)
        if (drawable->floor == game->current_floor &&
            drawable->x == x && drawable->y == y &&
            !drawable->is_walkable)
            return false;
    return true;
}
