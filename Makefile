CC = gcc
CFLAGS = -Wall -ggdb

SRC_TARGET = src
BIN_TARGET = bin
DATA_TARGET = data



$(SRC_TARRGET)/%.o: $(SRC_TARGET)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<
