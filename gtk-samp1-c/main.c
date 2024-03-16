#include <gtk/gtk.h>

#ifndef USE_DEFAULT_TITLE_BAR
#define USE_DEFAULT_TITLE_BAR 0
#endif

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
    GtkWidget *window = gtk_application_window_new (app);

    GdkDisplay *display = gdk_display_get_default();
    const gchar *display_type = g_type_name(gdk_display_get_type());

    const gchar *display_name = gdk_display_get_name(display);
    GString *title = g_string_new("GTK Sample 1 @");
    g_string_append(title, display_name);
    //g_string_append(title, " ");
    //g_string_append(title, display_type);

    if (USE_DEFAULT_TITLE_BAR) {
        gtk_window_set_title (GTK_WINDOW (window), g_string_free_and_steal(title));
    } else {
        GtkWidget *header_bar = gtk_header_bar_new();
        gtk_header_bar_set_show_close_button (GTK_HEADER_BAR (header_bar), TRUE);
        gtk_header_bar_set_title(GTK_HEADER_BAR (header_bar), g_string_free_and_steal(title));

        GtkWidget *btn_head1 = gtk_button_new();
        GtkWidget *btn_head1_label = gtk_label_new_with_mnemonic("_Hello");
        gtk_container_add (GTK_CONTAINER (btn_head1), btn_head1_label);
        gtk_header_bar_pack_start(GTK_HEADER_BAR (header_bar), btn_head1);

        gtk_window_set_titlebar(GTK_WINDOW (window), header_bar);
    }

    gtk_container_add (GTK_CONTAINER (window), gtk_text_view_new());

    gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
    gtk_window_present (GTK_WINDOW (window));
    gtk_widget_show_all(window);
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
