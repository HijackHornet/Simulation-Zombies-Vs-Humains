CC = gcc
CFLAGS = -Wall -std=c99 -lm

all: terrain.o caseDeplacement.o personnage.o coordonnees.o main.o
	$(CC) $(CFLAGS) caseDeplacement.o terrain.o personnage.o coordonnees.o main.o -o projet.out

main.c: terrain.c caseDeplacement.c coordonnees.c personnage.c
	$(CC) $(CFLAGS) -c terrain.c

terrain.c: caseDeplacement.c
	$(CC) $(CFLAGS)-c terrain.c

caseDeplacement.c: coordonnees.c personnage.c
	$(CC) $(CFLAGS) -c caseDeplacement.c

personnage.c: coordonnees.c
	$(CC) $(CFLAGS)-c personnage.c

coordonnees.c:
	$(CC) $(CFLAGS) -c coordonnees.c
