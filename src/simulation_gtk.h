#include <stdlib.h>
#include <gtk/gtk.h>

#include "simulation.h"
#include "SDL2/simulation_SDL2.h"
/**
   @brief Lance les fonction Sdl afin de lancer la simulation avec les param�tres donn�es
*/
void startSdlMain();
void startGTK(int argc, char *argv[]);
/**
   @brief Ouvre l'�diteur de maps en appelant les fontions sdl adapt�s
*/
void startSdlEditeurMain();
