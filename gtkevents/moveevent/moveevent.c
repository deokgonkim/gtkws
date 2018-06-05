#include <gtk/gtk.h>

void configure_callback(GtkWindow *window, GdkEvent *event, gpointer data);

int main(int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    // I'm not sure this is required or not?
    // Even when I comment out the line, the event handling still works.
    // But, I will remain it uncommented, since the tutorial said that.
    gtk_widget_add_events(GTK_WIDGET(window), GDK_CONFIGURE);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    g_signal_connect(G_OBJECT(window), "configure-event", G_CALLBACK(configure_callback), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

void configure_callback(GtkWindow *window, GdkEvent *event, gpointer data) {
    int x, y;
    GString *buf;

    x = event->configure.x;
    y = event->configure.y;

    buf = g_string_new(NULL);
    g_string_printf(buf, "%d, %d", x, y);

    gtk_window_set_title(window, buf->str);

    g_string_free(buf, TRUE);
}
