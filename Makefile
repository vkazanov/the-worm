CC      = gcc
LD      = gcc
CFLAGS  = -ggdb3 -Wall -Wextra -Werror -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wformat=2 -Wsign-conversion -Wswitch-default -Wmissing-format-attribute -Wformat-nonliteral -std=c11
LDFLAGS = -Wl,--no-undefined -ltcod
OBJ = main.o player.o map.o
DEP = map.h player.h

all: worm

worm: $(OBJ)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c  $(DEP)
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm $(OBJ)
	rm worm

.PHONY: clean
