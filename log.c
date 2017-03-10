#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "log.h"
#include "utils.h"

static const size_t LOG_MAX_SIZE = 10;
static const size_t LOG_MSG_BUFFER_SIZE = 256;

static size_t log_size = 0;

struct log_message_t {
    char* msg;
    struct log_message_t *next;
};
typedef struct log_message_t log_message_t;

static log_message_t *log = NULL;

static void log_push_msg(const char *msg);
static void log_pop_msg_last(void);

void log_msg(const char *message, ...)
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

void log_draw(TCOD_console_t *console)
{
    int line = 1;
    for (log_message_t *cur = log; cur; cur = cur->next) {
        TCOD_console_print(console, 0, line, "%d %s", line, cur->msg);
        line++;
    }
}


static void log_push_msg(const char *msg)
{
    log_message_t *new_msg = malloc(sizeof *new_msg);
    new_msg->msg = strndup(msg, LOG_MSG_BUFFER_SIZE);
    new_msg->next = log;
    log = new_msg;
    log_size++;
}

static void log_pop_msg_last()
{
    if (!log_size)
        return;
    log_message_t *cur = log;
    for (; cur && cur->next && cur->next->next; cur = cur->next);
    if (cur && cur->next) {
        FREE(cur->next->msg);
        FREE(cur->next);
        cur->next = NULL;
        log_size--;
    } else if (cur && !cur->next) {
        FREE(cur->msg);
        FREE(cur);
        log = NULL;
        log_size--;
    } else {
        assert(false);
    }
}
