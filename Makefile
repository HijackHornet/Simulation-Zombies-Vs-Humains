CC = gcc
CFLAGS = -Wall -ggdb $(shell pkg-config --cflags gtk+-3.0 SDL2_image && sdl2-config --cflags)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0 SDL2_image && sdl2-config --libs)

SRC = $(wildcard src/*.c) $(wildcard src/SDL2/*.c)
OBJ = $(SRC:.c=.o)

prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
