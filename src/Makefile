all: terrain.o caseDeplacement.o personnage.o coordonnees.o main.o
	gcc -Wall -std=c99 caseDeplacement.o terrain.o personnage.o coordonnees.o main.o -o projet.out -lm

main.c: terrain.c caseDeplacement.c coordonnees.c personnage.c
	gcc -Wall -std=c99 -c terrain.c -ggdb

terrain.c: caseDeplacement.c
	gcc -Wall -std=c99 -c terrain.c

caseDeplacement.c: coordonnees.c personnage.c
	gcc -Wall -std=c99 -c caseDeplacement.c -ggdb

personnage.c: coordonnees.c
	gcc -Wall -std=c99 -c personnage.c -ggdb

coordonnees.c:
	gcc -Wall -std=c99 -c coordonnees.c -ggdb
