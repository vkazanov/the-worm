#include <stdio.h>
#include <stdlib.h>

#include <libtcod/libtcod.h>


int main(int argc, char *argv[])
{
    (void) argc; (void) argv;
    uint16 player_x = 40, player_y = 25;
    TCOD_console_init_root(80, 50, "The Worm", false, TCOD_RENDERER_SDL);
    while (!TCOD_console_is_window_closed()) {
        TCOD_key_t key;
        TCOD_sys_check_for_event(TCOD_EVENT_KEY_PRESS, &key, NULL);
        switch(key.vk) {
        case TCODK_UP:
            player_y--;
            break;
        case TCODK_DOWN:
            player_y++;
            break;
        case TCODK_LEFT:
            player_x--;
            break;
        case TCODK_RIGHT:
            player_x++;
            break;
        default:
            break;
        }
        TCOD_console_clear(NULL);
        TCOD_console_put_char(NULL, player_x, player_y, '@', TCOD_BKGND_DEFAULT);
        TCOD_console_flush();
    }
    return EXIT_SUCCESS;
}
