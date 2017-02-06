#include <stdio.h>
#include <stdlib.h>

#include <libtcod/libtcod.h>


int main(int argc, char *argv[])
{
    (void) argc; (void) argv;
    TCOD_console_init_root(80, 40, "The Worm", false, TCOD_RENDERER_SDL);
    while (!TCOD_console_is_window_closed()) {
        puts("Checking...!");
        TCOD_key_t key;
        TCOD_sys_check_for_event(TCOD_EVENT_KEY_PRESS, &key, NULL);
        TCOD_console_clear(NULL);
        TCOD_console_flush();
    }

    puts("Hello, world!");
    return EXIT_SUCCESS;
}
