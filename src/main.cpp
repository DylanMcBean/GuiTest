#include <X11/Xlib.h>
#include <X11/keysym.h>

#include <iostream>

#include "x11shape.hpp"
#include "x11window.hpp"

void draw_shapes(X11Shape& shape) {
  shape.draw_rectangle(95, 95, 10, 10, false);
  shape.draw_circle(100, 100, 50, false);
  shape.draw_line(0, 0, 200, 200);
  shape.draw_line(0, 200, 200, 0);
}

int main() {
  X11Display display;
  X11Window window(display, 800, 800);
  X11Shape shape(display.display(), window.window());

  XSelectInput(display.display(), window.window(), KeyPressMask | ExposureMask);

  XEvent event;
  while (true) {
    XNextEvent(display.display(), &event);
    switch (event.type) {
      case Expose:
        draw_shapes(shape);
        break;
      case KeyPress: {
        KeySym key = XLookupKeysym(&event.xkey, 0);
        if (key == XK_Escape) {
          return 0;
        }
        break;
      }
    }
  }

  return 0;
}
