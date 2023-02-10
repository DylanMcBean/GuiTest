#ifndef X11SHAPE_HPP
#define X11SHAPE_HPP

#include <X11/Xlib.h>

class X11Shape {
 public:
  X11Shape(Display *display, Window window);
  void draw_rectangle(int x, int y, int width, int height, bool fill);
  void draw_circle(int x, int y, int radius, bool fill);
  void draw_line(int x1, int y1, int x2, int y2);

 private:
  Display *display_;
  Window window_;
};

#endif  // X11SHAPE_HPP