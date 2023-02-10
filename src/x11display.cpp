#include "x11display.hpp"

X11Display::X11Display() {
  display_ = XOpenDisplay(NULL);
  if (display_ == NULL) {
    std::cerr << "Cannot open display" << std::endl;
    exit(1);
  }

  screen_num_ = DefaultScreen(display_);
}

X11Display::~X11Display() { XCloseDisplay(display_); }

Display* X11Display::display() const { return display_; }

int X11Display::screen_num() const { return screen_num_; }