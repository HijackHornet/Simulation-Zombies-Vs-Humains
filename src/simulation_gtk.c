#include "simulation_gtk.h"

void startGtkMain(int argc, char ** argv){
  ChData     *data;
  GtkBuilder      *builder;

  gtk_init(&argc, &argv);

  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "../src/Launcher.glade", NULL);

  data = g_slice_new(ChData);

  (data -> window_main) = (GtkWidget *)gtk_builder_get_object(builder, "window_main");
  (data -> selecteurFichierSimulation) = (GtkFileChooser *)gtk_builder_get_object(builder, "selecteurFichierSimulation");
  (data -> selecteurNbZombies) = (GtkSpinButton *)gtk_builder_get_object(builder, "selecteurNbZombies");
  (data -> selecteurNbPoliciers) = (GtkSpinButton *)gtk_builder_get_object(builder, "selecteurNbPoliciers");
  (data -> selecteurNbCitoyens) = (GtkSpinButton *)gtk_builder_get_object(builder, "selecteurNbCitoyens");
  
  gtk_builder_connect_signals(builder, data);

  g_object_unref(builder);

  gtk_widget_show(data -> window_main);
  
  gtk_main();
}

G_MODULE_EXPORT gboolean bouton_lancement(GtkButton * button, ChData *data)
{
  char * filename = (char *)gtk_file_chooser_get_filename(data -> selecteurFichierSimulation);
  int nbZombies = (int)gtk_spin_button_get_value (data -> selecteurNbZombies);
  int nbPoliciers = (int)gtk_spin_button_get_value(data -> selecteurNbPoliciers);
  int nbCitoyens = (int)gtk_spin_button_get_value(data -> selecteurNbCitoyens);
  
  if(filename){
    Simulation * pSim = creerSimulation_sim(nbZombies, nbPoliciers, nbCitoyens, filename);

    lancerSimulationSDL2(pSim);
  }

  return FALSE;
}

G_MODULE_EXPORT gboolean bouton_editeur(GtkButton * button, ChData *data)
{
  return FALSE;
}
