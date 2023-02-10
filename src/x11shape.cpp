#include "x11shape.hpp"

X11Shape::X11Shape(Display *display, Window window)
    : display_(display), window_(window) {}

void X11Shape::draw_rectangle(int x, int y, int width, int height, bool fill) {
  if (fill) {
    XFillRectangle(display_, window_,
                   DefaultGC(display_, DefaultScreen(display_)), x, y, width,
                   height);
  } else {
    XDrawRectangle(display_, window_,
                   DefaultGC(display_, DefaultScreen(display_)), x, y, width,
                   height);
  }
}

void X11Shape::draw_circle(int x, int y, int radius, bool fill) {
  if (fill) {
    XFillArc(display_, window_, DefaultGC(display_, DefaultScreen(display_)),
             x - radius, y - radius, 2 * radius, 2 * radius, 0, 360 * 64);
  } else {
    XDrawArc(display_, window_, DefaultGC(display_, DefaultScreen(display_)),
             x - radius, y - radius, 2 * radius, 2 * radius, 0, 360 * 64);
  }
}

void X11Shape::draw_line(int x1, int y1, int x2, int y2) {
  XPoint points[2] = {{static_cast<short>(x1), static_cast<short>(y1)},
                      {static_cast<short>(x2), static_cast<short>(y2)}};
  XDrawLines(display_, window_, DefaultGC(display_, DefaultScreen(display_)),
             points, 2, CoordModeOrigin);
}