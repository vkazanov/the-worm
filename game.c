#include <stdlib.h>

#include "game.h"
#include "actor.h"

/* For now see everything */
static const int GAME_FOV_DEPTH = 1000;

void game_init(struct game_t *game)
{
    game->is_running = true;
    game->current_floor = 0;
    game->drawable_list = NULL;
    game->actor_list = NULL;
    game->maps[0] = &map1;
    game->maps[1] = &map2;
    game->maps[2] = &map3;
    game->tcod_map = TCOD_map_new(MAP_WIDTH, MAP_HEIGHT);
}

void game_update(struct game_t *game)
{
    map_t *map = game_get_current_map(game);
    for (size_t x = 0; x < MAP_WIDTH; x++) {
        for (size_t y = 0; y < MAP_HEIGHT; y++) {
            TCOD_map_set_properties(
                game->tcod_map,
                x, y,
                map_is_transparent(map, x, y),
                map_is_walkable(map, x, y)
            );
        }
    }
}

void game_fov_update(struct game_t *game, int8_t x, int8_t y)
{
    TCOD_map_compute_fov(game->tcod_map, x, y, GAME_FOV_DEPTH, true, FOV_BASIC);
}

bool game_in_fov(struct game_t *game, int8_t x, int8_t y)
{
    return TCOD_map_is_in_fov(game->tcod_map, x, y);
}

map_t *game_get_current_map(const struct game_t *game)
{
    return game->maps[game->current_floor];
}

void game_drawable_register(struct game_t *game, struct drawable_t *drawable)
{
    struct drawable_t *old_head = game->drawable_list;
    drawable->next = old_head;
    game->drawable_list = drawable;
}

void game_drawable_deregister(struct game_t *game, struct drawable_t *drawable)
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

void game_actor_list_act(struct game_t *game)
{
    for (struct actor_t *actor = game->actor_list; actor; actor = actor->next)
        actor->act(actor);
}

void game_actor_register(struct game_t *game, struct actor_t *actor)
{
    struct actor_t *old_head = game->actor_list;
    actor->next = old_head;
    game->actor_list = actor;
}

void game_actor_deregister(struct game_t *game, struct actor_t *actor)
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

void game_map_draw(const struct game_t *game, TCOD_console_t *console)
{
    map_draw(game_get_current_map(game), game->tcod_map, console);
}

void game_drawable_list_draw(const struct game_t *game, TCOD_console_t *console)
{
    for (struct drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next) {
        if (game->current_floor != drawable->floor)
            continue;
        if (!TCOD_map_is_in_fov(game->tcod_map, drawable->x, drawable->y))
            continue;
        TCOD_console_put_char(console, drawable->x, drawable->y, drawable->c, TCOD_BKGND_DEFAULT);
    }
}

bool game_is_walkable(const struct game_t *game, const int8_t x, const int8_t y)
{
    if (!map_is_walkable(game_get_current_map(game), x, y))
        return false;
    for (struct drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next)
        if (drawable->floor == game->current_floor &&
            drawable->x == x && drawable->y == y &&
            !drawable->is_walkable)
            return false;
    return true;
}
