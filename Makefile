CC      = gcc
LD      = gcc
CFLAGS  = -ggdb3 -Wall -Wextra -Werror -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wformat=2 -Wsign-conversion -Wswitch-default -Wmissing-format-attribute -Wformat-nonliteral -std=gnu11
LDFLAGS = -Wl,--no-undefined -ltcod
OBJ = main.o player.o map.o message.o log.o game.o monster.o drawable.o actor.o
DEP = map.h player.h message.h log.h game.h monster.h drawable.h actor.h

all: worm

worm: $(OBJ)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c  $(DEP)
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm -vf $(OBJ)
	rm -vf worm
	rm -vf core

.PHONY: clean
