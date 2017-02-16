#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libtcod/libtcod.h>

#include "log.h"

static const size_t LOG_MAX_SIZE = 10;
static const size_t LOG_MSG_BUFFER_SIZE = 256;

static TCOD_console_t *console = NULL;
static size_t log_size = 0;

struct log_message_t {
    char* msg;
    struct log_message_t *next;
};

static struct log_message_t *log = NULL;

static void log_push_msg(const char *const msg);
static void log_pop_msg_last(void);

void log_init(int w, int h)
{
    console = TCOD_console_new(w, h);
    TCOD_console_set_alignment(console, TCOD_LEFT);
}

void log_msg(const char *const message, ...)
{
    va_list ap;
    /* 256? */
    char buf[strlen(message)];
    va_start(ap, message);
    vsprintf(buf, message, ap);
    va_end(ap);
    log_push_msg(buf);
    while (log_size > LOG_MAX_SIZE)
        log_pop_msg_last();
}

void log_draw()
{
    TCOD_console_clear(console);
    for (size_t i = 0; i < 10; i++)
        TCOD_console_print(console, 0, i ,"message %d", i);
    TCOD_console_blit(console, 0, 0, 0, 0, NULL, 0, 0, 1, 0);
}


static void log_push_msg(const char *const msg)
{
    struct log_message_t **cur = &log;
    for (; *cur; cur = &(*cur)->next);
    struct log_message_t *new_msg = malloc(sizeof *new_msg);
    new_msg->msg = strndup(msg, LOG_MSG_BUFFER_SIZE);
    new_msg->next = NULL;
    *cur = new_msg;
    log_size++;
}

static void log_pop_msg_last()
{
    if (!log_size)
        return;
    struct log_message_t *cur = log;
    for (; cur->next; cur = cur->next);
    free(cur->next->msg);
    free(cur->next);
    cur->next = NULL;
    log_size--;
}
