#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <libtcod/libtcod.h>

#include "map.h"

struct player_body_t {
    int8_t x, y;
    bool is_hidden;
    struct player_body_t *prev;
    struct player_body_t *next;
};

struct player_t {
    struct player_body_t *head;
    bool do_increase_length;
    bool do_decrease_length;
};


void player_init(struct player_t *const player, const int8_t x, const int8_t y);

bool player_act(struct player_t *const player, const map_t *const map);

void player_hide_tail(struct player_t *const player);


void player_move_left(struct player_t *const player);

void player_move_right(struct player_t *const player);

void player_move_up(struct player_t *const player);

void player_move_down(struct player_t *const player);


bool player_can_move_left(const struct player_t *const player, const map_t *const map);

bool player_can_move_right(const struct player_t *const player, const map_t *const map);

bool player_can_move_up(const struct player_t *const player, const map_t *const map);

bool player_can_move_down(const struct player_t *const player, const map_t *const map);

bool player_can_move_higher(const struct player_t *const player, const map_t *const map);

bool player_can_move_lower(const struct player_t *const player, const map_t *const map);

bool player_can_quit(const struct player_t *const player, const map_t *const map);

bool player_can_pickup(const struct player_t *const player, const map_t *const map);


void player_pickup(struct player_t *const player, map_t *const map);

void player_increase_length(struct player_t *const player);

void player_decrease_length(struct player_t *const player);

void player_draw(const struct player_t *const player, TCOD_console_t *console);
