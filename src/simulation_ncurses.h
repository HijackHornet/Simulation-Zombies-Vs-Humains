#ifndef _NCURSES
#define _NCURSES

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>

#include "simulation.h"

void lanceSimulation(char * nomFic);

void afficheGrille(Simulation * pSim);

void boucleSimulation(Simulation * pSim);

#endif
