#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <libtcod/libtcod.h>

#include "maps.h"
#include "player.h"


static void player_draw(int8_t x, int8_t y)
{
    TCOD_console_put_char(NULL, x, y, '@', TCOD_BKGND_DEFAULT);
}

static void map_draw(map_t *map)
{
    for (int x = 0; x < MAP_WIDTH; x++)
        for (int y = 0; y < MAP_HEIGHT; y++) {
            char c;
            switch((*map)[y][x]) {
            case WL:
                c = '#';
                break;
            case FR:
                c = '.';
                break;
            case UP:
                c = '>';
                break;
            case DN:
                c = '<';
                break;
            default:
                assert(false);
                break;
            }
            TCOD_console_put_char(NULL, x, y, c, TCOD_BKGND_DEFAULT);

        }
}

static bool can_move_to(map_t *map, int8_t new_x, int8_t new_y)
{
    if (new_x < 0 || new_x >= MAP_WIDTH)
        return false;
    if (new_y < 0 || new_y >= MAP_WIDTH)
        return false;
    if ((*map)[new_y][new_x] == WL)
        return false;
    return true;
}

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
            if (can_move_to(map, player.x, player.y-1))
                player_move_up(&player);
            break;
        case TCODK_DOWN:
            if (can_move_to(map, player.x, player.y+1))
                player_move_down(&player);
            break;
        case TCODK_LEFT:
            if (can_move_to(map, player.x-1, player.y))
                player_move_left(&player);
            break;
        case TCODK_RIGHT:
            if (can_move_to(map, player.x+1, player.y))
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
        char c = (*map)[player.y][player.x];
        if (c == UP)
            current_floor++;
        else if (c == DN)
            current_floor--;

        /* Reset and draw afresh */
        TCOD_console_clear(NULL);
        map_draw(maps[current_floor]);
        player_draw(player.x, player.y);
        TCOD_console_flush();
    }
    return EXIT_SUCCESS;
}
