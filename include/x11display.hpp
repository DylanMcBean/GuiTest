#ifndef X11DISPLAY_HPP
#define X11DISPLAY_HPP

#include <X11/Xlib.h>

#include <cstdlib>
#include <iostream>

class X11Display {
 public:
  X11Display();
  ~X11Display();
  Display* display() const;
  int screen_num() const;

 private:
  Display* display_;
  int screen_num_;
};

#endif  // X11DISPLAY_HPP