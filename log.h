#pragma once

#include <libtcod/libtcod.h>

void log_init(int w, int h);

void log_msg(const char *message, ...) __attribute__ ((format (printf, 1, 2)));

void log_draw(TCOD_console_t *console);
