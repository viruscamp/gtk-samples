#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();
};

MyWindow::MyWindow()
{
    auto display = Gdk::Display::get_default();
    auto display_name = display->get_name();
    Glib::ustring title = "GTK Sample 2 @";
    title.append(display_name);
    set_title(title);
    set_default_size(400, 400);
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");
  MyWindow window;
  return app->run(window, argc, argv);
}
