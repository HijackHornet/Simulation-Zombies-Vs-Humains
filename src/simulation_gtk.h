/**
   @file simulation_gtk.h
   @brief  Définit les fonction appelant à la librairie gtk
*/
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
  GtkFileChooser *selecteurDossierEditeur;
  GtkEntry *selecteurFichierEditeur;
  GtkSpinButton *selecteurDimXEditeur;
  GtkSpinButton *selecteurDimYEditeur;

  gchar * fichierALire;
};

/**
   @brief Lance les fonction Sdl afin de lancer la simulation avec les paramètres données
*/
void startGtkMain(int argc, char ** argv);
/**
   @brief Ouvre l'éditeur de maps en appelant les fontions sdl adaptés
*/
void startSdlEditeurMain();
