#ifndef X11WINDOW_HPP
#define X11WINDOW_HPP

#include <X11/Xlib.h>

#include "x11display.hpp"

class X11Window {
 public:
  X11Window(const X11Display &display, int width, int height);
  ~X11Window();
  Window window() const;

 private:
  Display *display_;
  int screen_num_;
  Window window_;
};

#endif  // X11WINDOW_HPP