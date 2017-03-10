#include <stdlib.h>

#include "game.h"
#include "actor.h"

/* For now see everything */
static const int GAME_FOV_DEPTH = 1000;

void game_init(game_t *game)
{
    game->is_running = true;
    game->drawable_list = NULL;
    game->actor_list = NULL;
    map_init(&game->map);
    game->tcod_map = TCOD_map_new(MAP_WIDTH, MAP_HEIGHT);
}

void game_fov_update(game_t *game, int8_t player_x, int8_t player_y)
{
    map_t *map = game_get_map(game);
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
    TCOD_map_compute_fov(
        game->tcod_map,
        player_x, player_y,
        GAME_FOV_DEPTH,
        true,
        FOV_BASIC
    );
}

bool game_in_fov(game_t *game, int8_t x, int8_t y)
{
    return TCOD_map_is_in_fov(game->tcod_map, x, y);
}

map_t *game_get_map(game_t *game)
{
    return &game->map;
}

void game_drawable_register(game_t *game, drawable_t *drawable)
{
    drawable_t *old_head = game->drawable_list;
    drawable->next = old_head;
    game->drawable_list = drawable;
}

void game_drawable_deregister(game_t *game, drawable_t *drawable)
{
    for (drawable_t *this = game->drawable_list, *prev = NULL ; this; prev = this, this = this->next) {
        if (this == drawable) {
            if (prev)
                prev->next = this->next;
            else
                game->drawable_list = this->next;
        }
    }
}

void game_actor_register(game_t *game, actor_t *actor)
{
    actor_t *old_head = game->actor_list;
    actor->next = old_head;
    game->actor_list = actor;
}

void game_actor_deregister(game_t *game, actor_t *actor)
{
    for (actor_t *this = game->actor_list, *prev = NULL ; this; prev = this, this = this->next) {
        if (this == actor) {
            if (prev)
                prev->next = this->next;
            else
                game->actor_list = this->next;
        }
    }
}

void game_map_draw(game_t *game, TCOD_console_t *console)
{
    map_draw(game_get_map(game), game->tcod_map, console);
}

void game_drawable_list_draw(const game_t *game, TCOD_console_t *console)
{
    for (drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next) {
        if (game_get_floor(game) != drawable->floor)
            continue;
        if (!TCOD_map_is_in_fov(game->tcod_map, drawable->x, drawable->y))
            continue;
        TCOD_console_put_char(console, drawable->x, drawable->y, drawable->c, TCOD_BKGND_DEFAULT);
    }
}

bool game_is_walkable(game_t *game, const int8_t x, const int8_t y)
{
    if (!map_is_walkable(game_get_map(game), x, y))
        return false;
    for (drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next)
        if (drawable->floor == game_get_floor(game) &&
            drawable->x == x && drawable->y == y &&
            !drawable->is_walkable)
            return false;
    return true;
}

drawable_t *game_find_attackable(game_t *game, int8_t new_x, int8_t new_y)
{
    for (drawable_t *drawable = game->drawable_list; drawable; drawable = drawable->next) {
        bool found = drawable->is_attackable
            && drawable->x == new_x
            && drawable->y == new_y;
        if (found)
            return drawable;
    }
    return NULL;
}

int8_t game_get_floor(const game_t *game)
{
    return game->map.current_floor;
}

void game_increase_floor(game_t *game)
{
    game->map.current_floor++;
}

void game_decrease_floor(game_t *game)
{
    game->map.current_floor--;
}
