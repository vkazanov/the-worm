#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "game.h"
#include "message.h"
#include "player.h"
#include "log.h"
#include "monster.h"


const int WINDOW_WIDTH = 80, WINDOW_HEIGHT = 50;
const int LOG_WIDTH = 80, LOG_HEIGHT = 10;


int main(int argc, char *argv[])
{
    (void) argc; (void) argv;

    /* Init GUI */
    TCOD_console_init_root(WINDOW_WIDTH, WINDOW_HEIGHT, "The Worm", false, TCOD_RENDERER_SDL);

    TCOD_console_t map_console = TCOD_console_new(MAP_WIDTH, MAP_HEIGHT);
    TCOD_console_t log_console = TCOD_console_new(LOG_WIDTH, LOG_HEIGHT);

    /* Init the player */
    struct game_t game;
    game_init(&game);

    struct player_t player;
    player_init(&player, &game, 10, 20);

    struct monster_t monster;
    monster_init(&monster, &game, 5, 5);

    /* Main game loop */
    while (game.is_running) {
        map_t *map = game_get_current_map(&game);

        /* First, reset and draw everything */
        TCOD_console_clear(NULL);
        TCOD_console_clear(map_console);
        TCOD_console_clear(log_console);

        map_draw(map, map_console);
        game_drawable_list_draw(&game, map_console);

        log_draw(log_console);

        TCOD_console_blit(map_console, 0, 0, 0, 0, NULL, 0, 0, 1, 1);
        TCOD_console_blit(log_console, 0, 0, 0, 0, NULL, 0, MAP_HEIGHT, 1, 1);
        TCOD_console_flush();

        /* Then, check for state updates */
        player_act(player.actor);
        monster_act(monster.actor);

        /* Additinal loop exit checks */
        if (TCOD_console_is_window_closed())
            game.is_running = false;
    }

    return EXIT_SUCCESS;
}
