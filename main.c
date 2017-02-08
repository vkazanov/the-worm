#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <libtcod/libtcod.h>

#include "map.h"
#include "player.h"


int main(int argc, char *argv[])
{
    (void) argc; (void) argv;
    uint8_t current_floor = 0;
    struct player_t player = {
        20, 12
    };

    /* Check user input */
    TCOD_console_init_root(50, 30, "The Worm", false, TCOD_RENDERER_SDL);
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
            if (key.c == 'q') {
                return EXIT_SUCCESS;
            }
            break;
        default:
            break;
        }

        /* See if actions should be taken */
        if (player_can_move_higher(&player, map))
            current_floor++;
        else if (player_can_move_lower(&player, map))
            current_floor--;

        /* Reset and draw afresh */
        TCOD_console_clear(NULL);
        map_draw(maps[current_floor]);
        player_draw(&player);
        TCOD_console_flush();
    }
    return EXIT_SUCCESS;
}
