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

    uint8_t current_floor = 0;
    struct player_t player;
    player_init(&player, 10, 20);

    /* Main game loop */
    while (game.is_running) {

        /* First, reset and draw everything */
        TCOD_console_clear(NULL);
        TCOD_console_clear(map_console);
        TCOD_console_clear(log_console);

        map_draw(maps[current_floor], map_console);
        player_draw(&player, map_console);
        TCOD_console_blit(map_console, 0, 0, 0, 0, NULL, 0, 0, 1, 1);

        log_draw(log_console);
        TCOD_console_blit(log_console, 0, 0, 0, 0, NULL, 0, MAP_HEIGHT, 1, 1);

        TCOD_console_flush();

        /* Then, check for state updates */
        map_t *map = maps[current_floor];

        game.is_running = player_act(&player, map);

        /* See if actions should be taken */
        if (player_can_move_higher(&player, map)) {
            current_floor++;
            player_hide_tail(&player);
            log_msg("%s","Moved higher");
        } else if (player_can_move_lower(&player, map)) {
            current_floor--;
            player_hide_tail(&player);
            log_msg("%s","Moved lower");
        } else if (player_can_quit(&player, map)) {
            message("Game won!");
            game.is_running = false;
            continue;
        } else if (player_can_pickup(&player, map)) {
            player_pickup(&player, map);
            log_msg("%s", "Object found!");
        }

        /* Additinal loop checks */
        if (TCOD_console_is_window_closed()) {
            game.is_running = false;
            continue;
        }

    }

    return EXIT_SUCCESS;
}
