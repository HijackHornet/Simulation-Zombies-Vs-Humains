/**
   @file simulation_gtk.h
   @brief  Définit les fonction appelant à la librairie gtk
*/
#include <stdlib.h>
#include <gtk/gtk.h>

#include "simulation.h"
#include "SDL2/simulation_SDL2.h"
/**
   @brief Lance les fonction Sdl afin de lancer la simulation avec les paramètres données
*/
void startSdlMain(int nbZombies, int nbPoliciers, int nbCitoyens);
void startGTK(int argc, char *argv[]);
/**
   @brief Ouvre l'éditeur de maps en appelant les fontions sdl adaptés
*/
void startSdlEditeurMain();
