#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
    GtkWidget *window = gtk_application_window_new (app);

    GdkDisplay* display = gdk_display_get_default();
    const gchar* display_type = g_type_name(gdk_display_get_type());

    const gchar* display_name = gdk_display_get_name(display);
    GString* title = g_string_new("GTK Sample 1 @");
    g_string_append(title, display_name);
    //g_string_append(title, " ");
    //g_string_append(title, display_type);

    gtk_window_set_title (GTK_WINDOW (window), g_string_free_and_steal(title));
    gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
    gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
