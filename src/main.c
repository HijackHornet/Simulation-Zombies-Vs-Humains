#include "defs.h"
//#include "simulation_ncurses.h"
#include <stdlib.h>
#include <gtk/gtk.h>

void startSdlMain(){
    //testFonctions_Coord();
    //testFonctions_terr();
    //testFonctions_perso();
    //testFonctions_sim();
//    lanceSimulation("FichierTestLecture");
    Simulation * pSim = creerSimulation_sim(50, 50, 50, "FichierTestLecture");
    lancerSimulationSDL2(pSim);
}


int main (int argc, char *argv[])
{
  GtkWidget *button = NULL;
  GtkWidget *win = NULL;
  GtkWidget *vbox = NULL;
  gint a,b;
  a=350; b=700;

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_resize (win, a, b);

//  gtk_container_set_border_width (GTK_CONTAINER (win), 175);
  gtk_window_set_title (GTK_WINDOW (win), "Simulation Humains VS Zombie Launcher");
  gtk_window_move(win, 70, 150);

  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);

  /* Create a vertical box with buttons */
  vbox = gtk_vbox_new (TRUE, 60);
  gtk_container_add (GTK_CONTAINER (win), vbox);

  button = gtk_button_new_with_label ("Lancer Simulation");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (startSdlMain), (gpointer) win);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);


  /* Enter the main loop */
  gtk_widget_show_all (win);
  gtk_main ();
  return 0;
}
