#include <stdlib.h>

#include "simulation_gtk.h"

int main(int argc, char ** argv)
{
  //startSdlMain(10, 10, 10);

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

  return 0;
}

// called when window is closed
G_MODULE_EXPORT void boutton_launch_cliquee(GtkButton * button, gpointer user_data)
{
  startSdlMain(10, 10, 10);
  gtk_main_quit();
}

G_MODULE_EXPORT void boutton_editor_cliquee(GtkButton * button, gpointer user_data)
{
  startSdlEditeurMain();
  gtk_main_quit();
}

G_MODULE_EXPORT void boutton_fichier_cliquee(GtkFileChooser *filechooserbutton1)
{
  gchar *cNome;
  cNome = gtk_file_chooser_get_filename(filechooserbutton1);

  printf("\n%s", cNome);
}

