#include <stdlib.h>

#include "actor.h"
#include "utils.h"

void actor_init(actor_t *actor, actor_act_function_t *act, void *parent, game_t *game)
{
    actor->act = act;
    actor->parent = parent;
    actor->game = game;
    actor->next = NULL;
}

actor_t *actor_make(actor_act_function_t *act_function, void *parent, game_t *game)
{
    actor_t *actor = MALLOC(sizeof *actor);
    actor_init(actor, act_function, parent, game);
    return actor;
}

void actor_destroy(actor_t *actor)
{
    FREE(actor);
}
