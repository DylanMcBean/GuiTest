#include "x11window.hpp"

X11Window::X11Window(const X11Display &display, int width, int height)
    : display_(display.display()), screen_num_(display.screen_num()) {
  int screen_width = DisplayWidth(display_, screen_num_);
  int screen_height = DisplayHeight(display_, screen_num_);
  int x = (screen_width - width) / 2;
  int y = (screen_height - height) / 2;
  window_ = XCreateSimpleWindow(
      display_, RootWindow(display_, screen_num_), x, y, width, height, 1,
      BlackPixel(display_, screen_num_), WhitePixel(display_, screen_num_));
  XSelectInput(display_, window_, ExposureMask | KeyPressMask);
  XMapWindow(display_, window_);
}

X11Window::~X11Window() { XDestroyWindow(display_, window_); }

Window X11Window::window() const { return window_; }