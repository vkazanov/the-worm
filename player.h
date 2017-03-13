#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "game.h"

struct player_t;
typedef struct player_t player_t;

struct player_body_t;
typedef struct player_body_t player_body_t;

struct player_body_t {
    player_t *player;
    drawable_t *drawable;

    player_body_t *prev;
    player_body_t *next;
};

struct player_t {
    game_t *game;
    actor_t *actor;

    player_body_t *head;

    int8_t length;
    bool do_increase_length;
    bool do_decrease_length;
};


void player_init(player_t *player, game_t *game, const int8_t x, const int8_t y);

void player_act(actor_t *actor);

void player_fov_update(player_t *player);

void player_move_vertically(player_t *player);


bool player_can_move_left(const player_t *player);

bool player_can_move_right(const player_t *player);

bool player_can_move_up(const player_t *player);

bool player_can_move_down(const player_t *player);

bool player_can_move_higher(const player_t *player);

bool player_can_move_lower(const player_t *player);

bool player_can_quit(const player_t *player);

bool player_can_pickup(const player_t *player);


void player_pickup(player_t *player);
