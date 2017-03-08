#pragma once

#include "game.h"

struct actor_t;
typedef struct actor_t actor_t;

typedef void actor_act_function_t(actor_t *actor);

struct actor_t {
    void *parent;
    game_t *game;
    actor_act_function_t *act;

    actor_t *next;
};

void actor_init(actor_t *actor, actor_act_function_t *act_function, void *parent, game_t *game);

actor_t *actor_make(actor_act_function_t *act_function, void *parent, game_t *game);
