/**
   @file simulation_ncurses.h
   @brief  Définit les fonction appelant à la librairie nCurses
*/
#ifndef _NCURSES
#define _NCURSES

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>

#include "simulation.h"

void lancerSimulationNcurses(char * nomFic);

void afficheGrille(Simulation * pSim);

void boucleSimulation(Simulation * pSim);

#endif
