#pragma once

#include "game.h"

struct actor_t;
typedef void (actor_act_function_t)(struct actor_t *actor);

struct actor_t {
    void *parent;
    struct game_t *game;
    actor_act_function_t *act;

    struct actor_t *next;
};

void actor_init(struct actor_t *actor, actor_act_function_t *act_function, void *parent, struct game_t *game);

struct actor_t *actor_make(actor_act_function_t *act_function, void *parent, struct game_t *game);
