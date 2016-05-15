#include <stdlib.h>
#include <gtk/gtk.h>

#include "simulation_gtk.h"
#include <time.h>

int main (int argc, char ** argv)
{
  srand (time(NULL));
  
  /*Simulation * pSim = creerSimulation_sim(1, 0, 1, "FichierTestLecture");
  propagerChampsPersos(pSim);
  afficherChamps(getTerrain_sim(pSim));*/
  startSdlMain();
  /*lancerSimulationSDL2Editeur();
  GtkBuilder      *builder;
  GtkWidget       *window;

  gtk_init(&argc, &argv);

  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "../src/Launcher.glade", NULL);

  window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
  gtk_builder_connect_signals(builder, NULL);

  g_object_unref(builder);

  gtk_widget_show(window);
  gtk_main();
  */



  return 0;
}

// called when window is closed
void boutton_launch_cliquee(GtkButton * button, gpointer user_data)
{
  gtk_main_quit();
}

