CC      = gcc
LD      = gcc
CFLAGS  = -ggdb3 -Wall -Wextra -Werror -Wconversion -std=c11
LDFLAGS = -Wl,--no-undefined
OBJ = main.o

all: worm

worm: $(OBJ)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm $(OBJ)
	rm worm

.PHONY: clean
