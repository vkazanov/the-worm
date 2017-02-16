#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <libtcod/libtcod.h>

#include "map.h"
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
    log_init(LOG_WIDTH, LOG_HEIGHT);

    /* Init the player */
    uint8_t current_floor = 0;
    struct player_t player;
    player_init(&player, 10, 20);

    /* Main game loop */
    while (!TCOD_console_is_window_closed()) {
        map_t *map = maps[current_floor];
        TCOD_key_t key;
        TCOD_sys_check_for_event(TCOD_EVENT_KEY_PRESS, &key, NULL);
        switch(key.vk) {
        case TCODK_UP:
            if (player_can_move_up(&player, map))
                player_move_up(&player);
            break;
        case TCODK_DOWN:
            if (player_can_move_down(&player, map))
                player_move_down(&player);
            break;
        case TCODK_LEFT:
            if (player_can_move_left(&player, map))
                player_move_left(&player);
            break;
        case TCODK_RIGHT:
            if (player_can_move_right(&player, map))
                player_move_right(&player);
            break;
        case TCODK_CHAR:
            if (key.c == 'q')
                return EXIT_SUCCESS;
            else if (key.c == 'i') {
                player_increase_length(&player);
                log_msg("%s","Length increased");
            } else if (key.c == 'd') {
                player_decrease_length(&player);
                log_msg("%s","Length decreased");
            } else if (key.c == 'c') {
                message("A key pressed!");
            }
            break;
        default:
            break;
        }

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
            return EXIT_SUCCESS;
        }

        /* Reset and draw afresh */
        TCOD_console_clear(NULL);
        map_draw(maps[current_floor]);
        player_draw(&player);
        log_draw(0, MAP_HEIGHT);
        TCOD_console_flush();
    }

    return EXIT_SUCCESS;
}
