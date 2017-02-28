#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "game.h"

struct player_body_t {
    struct drawable_t *drawable;

    struct player_body_t *prev;
    struct player_body_t *next;
};

struct player_t {
    struct game_t *game;
    struct actor_t *actor;

    struct player_body_t *head;

    bool do_increase_length;
    bool do_decrease_length;
};


void player_init(struct player_t *player, struct game_t *game, const int8_t x, const int8_t y);

void player_act(struct actor_t *actor);

void player_fov_update(struct player_t *player);

void player_move_left(struct player_t *player);

void player_move_right(struct player_t *player);

void player_move_up(struct player_t *player);

void player_move_down(struct player_t *player);

void player_move_vertically(struct player_t *player);


bool player_can_move_left(const struct player_t *player);

bool player_can_move_right(const struct player_t *player);

bool player_can_move_up(const struct player_t *player);

bool player_can_move_down(const struct player_t *player);

bool player_can_move_higher(const struct player_t *player);

bool player_can_move_lower(const struct player_t *player);

bool player_can_quit(const struct player_t *player, const map_t *map);

bool player_can_pickup(const struct player_t *player, const map_t *map);


void player_pickup(struct player_t *player, map_t *map);
