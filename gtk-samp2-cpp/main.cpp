#include <gtkmm.h>

#ifndef USE_DEFAULT_TITLE_BAR
#define USE_DEFAULT_TITLE_BAR 0
#endif

class MyWindow : public Gtk::Window
{
private:
  Gtk::HeaderBar header;
  Gtk::Button btn_head1;
  Gtk::Label btn_head1_label;
  Gtk::TextView text_view;
public:
  MyWindow();
};

MyWindow::MyWindow()
{
  auto display = Gdk::Display::get_default();
  auto display_name = display->get_name();
  Glib::ustring title = "GTK Sample 2 @";
  title.append(display_name);

  if (USE_DEFAULT_TITLE_BAR) {
    set_title(title);
  } else {
    btn_head1_label.set_text_with_mnemonic("_Hello");
    btn_head1.add(btn_head1_label);

    header.set_show_close_button(true);
    header.set_title(title);
    header.pack_start(btn_head1);

    set_titlebar(header);
  }
  set_default_size(400, 400);

  add(text_view);

  show_all();
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");
  MyWindow window;
  return app->run(window, argc, argv);
}
