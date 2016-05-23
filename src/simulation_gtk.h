/**
   @file simulation_gtk.h
   @brief  Définit les fonction appelant à la librairie gtk
*/
#include <stdlib.h>
#include <gtk/gtk.h>

#include "simulation.h"
#include "SDL2/simulation_SDL2.h"

/*Structure de stockage des widgets*/
typedef struct _ChData ChData;
struct _ChData
{
  GtkWidget *window_main;
  GtkFileChooser *selecteurFichierSimulation;
  GtkSpinButton *selecteurNbZombies;
  GtkSpinButton *selecteurNbPoliciers;
  GtkSpinButton *selecteurNbCitoyens;
  GtkFileChooser *selecteurDossierEditeur;
  GtkEntry *selecteurFichierEditeur;
  GtkSpinButton *selecteurDimXEditeur;
  GtkSpinButton *selecteurDimYEditeur;
};

/**
   @brief Lance l'interface GTK
*/
void startGtkMain(int argc, char ** argv);
