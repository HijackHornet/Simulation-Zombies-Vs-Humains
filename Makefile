CC = gcc
CFLAGS = -Wall -ggdb $(shell pkg-config --cflags gtk+-3.0 SDL2_image && sdl2-config --cflags)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0 SDL2_image && sdl2-config --libs) -lm -lncurses -rdynamic

SRC = $(wildcard src/*.c) $(wildcard src/SDL2/*.c)
OBJ = $(SRC:.c=.o)

bin/prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f bin/prog
	rm -f src/*.o
	rm -f src/SDL2/*.o
