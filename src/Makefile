CC = gcc
CFLAGS = -Wall -std=c99 -lm -ggdb

all: terrain.o caseDeplacement.o personnage.o coordonnees.o main.o simulation.o
	$(CC) $(CFLAGS) caseDeplacement.o terrain.o personnage.o coordonnees.o simulation.o main.o -o projet.out

main.c: terrain.c caseDeplacement.c coordonnees.c personnage.c simulation.c
	$(CC) $(CFLAGS) -c terrain.c

simulation.c: terrain.c caseDeplacement.c coordonnees.c personnage.c
	$(CC) $(CFLAGS) -c simulation.c

terrain.c: caseDeplacement.c
	$(CC) $(CFLAGS) -c terrain.c

caseDeplacement.c: coordonnees.c personnage.c
	$(CC) $(CFLAGS) -c caseDeplacement.c

personnage.c: coordonnees.c
	$(CC) $(CFLAGS) -c personnage.c

coordonnees.c:
	$(CC) $(CFLAGS) -c coordonnees.c

clean:
	rm -f *.o
