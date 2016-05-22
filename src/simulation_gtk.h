#include <stdlib.h>
#include <gtk/gtk.h>

#include "simulation.h"
#include "SDL2/simulation_SDL2.h"

/* Main data structure definition */
typedef struct _ChData ChData;
struct _ChData
{
  /* Widgets */
  GtkWidget *window_main;  /* Main application window */
  GtkFileChooser *selecteurFichierSimulation;
  GtkSpinButton *selecteurNbZombies;
  GtkSpinButton *selecteurNbPoliciers;
  GtkSpinButton *selecteurNbCitoyens;

  gchar * fichierALire;
};

/**
   @brief Lance les fonction Sdl afin de lancer la simulation avec les param�tres donn�es
*/
void startGtkMain(int argc, char ** argv);
/**
   @brief Ouvre l'�diteur de maps en appelant les fontions sdl adapt�s
*/
void startSdlEditeurMain();
