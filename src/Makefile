all: terrain.o caseDeplacement.o personnage.o coordonnees.o
	gcc -Wall -std=c99 caseDeplacement.o terrain.o personnage.o coordonnees.o -o projet.out -lm

terrain.c: caseDeplacement.c
	gcc -Wall -std=c99 -c terrain.c

caseDeplacement.c: coordonnees.c personnage.c
	gcc -Wall -std=c99 -c caseDeplacement.c

personnage.c: coordonnees.c
	gcc -Wall -std=c99 -c personnage.c

coordonnees.o:
	gcc -Wall -std=c99 -c coordonnees.c
