#include <X11/keysym.h>

#include <iostream>

#include "player.hpp"
#include "x11shape.hpp"
#include "x11window.hpp"

void draw_shapes(X11Shape& shape) {
  shape.draw_rectangle(95, 95, 10, 10, false);
}

typedef struct Movement {
  int x, y;
} Movement;

int main() {
  X11Display display;
  X11Window window(display, 800, 800);
  X11Shape shape(display.display(), window.window());

  Player e(50, 50);
  Movement m;

  XSelectInput(display.display(), window.window(),
               KeyPressMask | KeyReleaseMask | ExposureMask);

  XEvent event;
  while (true) {
    m = {0, 0};
    XNextEvent(display.display(), &event);
    switch (event.type) {
      case Expose:
        break;
      case KeyPress:
      case KeyRelease: {
        char keymap[32];
        XQueryKeymap(display.display(), keymap);

        // Check if 'w' key is pressed
        if (keymap[XKeysymToKeycode(display.display(), XK_w) / 8] &
            (1 << (XKeysymToKeycode(display.display(), XK_w) % 8))) {
          m.y -= e.move_speed;
        }

        // Check if 'a' key is pressed
        if (keymap[XKeysymToKeycode(display.display(), XK_a) / 8] &
            (1 << (XKeysymToKeycode(display.display(), XK_a) % 8))) {
          m.x -= e.move_speed;
        }

        // Check if 's' key is pressed
        if (keymap[XKeysymToKeycode(display.display(), XK_s) / 8] &
            (1 << (XKeysymToKeycode(display.display(), XK_s) % 8))) {
          m.y += e.move_speed;
        }

        // Check if 'd' key is pressed
        if (keymap[XKeysymToKeycode(display.display(), XK_d) / 8] &
            (1 << (XKeysymToKeycode(display.display(), XK_d) % 8))) {
          m.x += e.move_speed;
        }

        // Check if 'Escape' key is pressed
        if (keymap[XKeysymToKeycode(display.display(), XK_Escape) / 8] &
            (1 << (XKeysymToKeycode(display.display(), XK_Escape) % 8))) {
          return 0;
        }

        e.MoveRelative(m.x, m.y);
        break;
      }
    }

    // Draw Stuff Here
    XClearWindow(display.display(), window.window());
    shape.draw_rectangle(e.x - 5, e.y - 5, 10, 10, false);
  }

  return 0;
}