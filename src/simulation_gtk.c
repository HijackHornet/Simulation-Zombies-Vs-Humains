#include "simulation_gtk.h"

void startGtkMain(int argc, char ** argv){
  ChData     *data;
  GtkBuilder      *builder;

  gtk_init(&argc, &argv);

  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "../src/Launcher.glade", NULL);

  data = g_slice_new(ChData);

  //Récupération des widgets dans ChData
  (data -> window_main) = (GtkWidget *)gtk_builder_get_object(builder, "window_main");
  (data -> selecteurFichierSimulation) = (GtkFileChooser *)gtk_builder_get_object(builder, "selecteurFichierSimulation");
  (data -> selecteurNbZombies) = (GtkSpinButton *)gtk_builder_get_object(builder, "selecteurNbZombies");
  (data -> selecteurNbPoliciers) = (GtkSpinButton *)gtk_builder_get_object(builder, "selecteurNbPoliciers");
  (data -> selecteurNbCitoyens) = (GtkSpinButton *)gtk_builder_get_object(builder, "selecteurNbCitoyens");
  (data -> selecteurDossierEditeur) = (GtkFileChooser *)gtk_builder_get_object(builder, "selecteurDossierEditeur");
  (data -> selecteurFichierEditeur) = (GtkEntry *)gtk_builder_get_object(builder, "selecteurNomFichier");
  (data -> selecteurDimXEditeur) = (GtkSpinButton *)gtk_builder_get_object(builder, "selecteurDimX");
  (data -> selecteurDimYEditeur) = (GtkSpinButton *)gtk_builder_get_object(builder, "selecteurDimY");

  //Connecte la structure data aux fonctions de callback
  gtk_builder_connect_signals(builder, data);

  //Déréférence le builder qui n'est plus nécessaire
  g_object_unref(builder);

  //Affichage de la fenêtre principale
  gtk_widget_show(data -> window_main);

  //Lancement de la boucle principale
  gtk_main();

  //Libération de data
  g_slice_free(ChData, data);
}

G_MODULE_EXPORT gboolean bouton_lancement(GtkButton * button, ChData *data)
{
  char * filename = (char *)gtk_file_chooser_get_filename(data -> selecteurFichierSimulation);
  int nbZombies = (int)gtk_spin_button_get_value (data -> selecteurNbZombies);
  int nbPoliciers = (int)gtk_spin_button_get_value(data -> selecteurNbPoliciers);
  int nbCitoyens = (int)gtk_spin_button_get_value(data -> selecteurNbCitoyens);
  
  if(filename){ //vérifie si un chemin a bien été rentré, les autres parmètres sont assurés par Gtk
    Simulation * pSim = creerSimulation_sim(nbZombies, nbPoliciers, nbCitoyens, filename);

    lancerSimulationSDL2(pSim);
  }

  return FALSE;
}

G_MODULE_EXPORT gboolean bouton_editeur(GtkButton * button, ChData *data)
{
  const char * filename = (const char *)gtk_entry_get_text(data -> selecteurFichierEditeur);
  char * folder = (char *)gtk_file_chooser_get_filename(data -> selecteurDossierEditeur);
  
  int dimX = (int)gtk_spin_button_get_value(data -> selecteurDimXEditeur);
  int dimY = (int)gtk_spin_button_get_value(data -> selecteurDimYEditeur);

  if(strlen(filename) && folder){ //vérifie qu'un nom de fichier a été rentré et un chemin sélectionné
    strcat(folder, "/");
    strcat(folder, filename);
    strcat(folder, ".terrain");
    lancerSimulationSDL2Editeur(folder, dimX, dimY);
  }
  
  return FALSE;
}
