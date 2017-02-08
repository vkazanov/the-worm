CC      = gcc
LD      = gcc
CFLAGS  = -ggdb3 -Wall -Wextra -Werror -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wformat=2 -Wsign-conversion -Wswitch-default -Wmissing-format-attribute -Wformat-nonliteral -std=c11
LDFLAGS = -Wl,--no-undefined -ltcod
OBJ = main.o player.o
DEPS = maps.h

all: worm

worm: $(OBJ)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm $(OBJ)
	rm worm

.PHONY: clean
