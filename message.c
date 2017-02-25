#include <stdio.h>

#include <libtcod/libtcod.h>

#include "message.h"

const char *continue_msg = "Press any key to continue...";

void message(char* msg)
{
    printf("%s\n", msg);
    printf("Press any key to continue...\n");
    TCOD_console_print_rect_ex(
        NULL, 10, 10, 50, 6, TCOD_BKGND_DEFAULT, TCOD_CENTER,
        "%s\n\n%s", msg, continue_msg
    );
    TCOD_console_flush();
    TCOD_key_t key;
    TCOD_sys_wait_for_event(TCOD_EVENT_KEY_PRESS, &key, NULL, true);
    printf("Done\n");
}
