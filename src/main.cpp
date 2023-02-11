#include <X11/keysym.h>

#include <iostream>

#include "player.hpp"
#include "x11shape.hpp"
#include "x11window.hpp"

typedef struct Movement {
  int x, y;
} Movement;

bool IsKeyPressed(X11Display &display, char *keymap, KeySym key) {
  return (keymap[XKeysymToKeycode(display.display(), key) / 8] &
          (1 << (XKeysymToKeycode(display.display(), key) % 8)));
}

int main() {
  X11Display display;
  X11Window window(display, 800, 800);
  X11Shape shape(display.display(), window.window());

  Player player(50, 50);
  Movement movement;

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
      case KeyRelease:
        char keymap[32];
        XQueryKeymap(display.display(), keymap);

        if (IsKeyPressed(display, keymap, XK_w)) movement.y--;
        if (IsKeyPressed(display, keymap, XK_a)) movement.x--;
        if (IsKeyPressed(display, keymap, XK_s)) movement.y++;
        if (IsKeyPressed(display, keymap, XK_d)) movement.x++;

        if (IsKeyPressed(display, keymap, XK_Escape)) return 0;

        // normolize values to cancel diagonal boost
        if (movement.x != 0 && movement.y != 0) {
          movement.x /= std::sqrt(2);
          movement.y /= std::sqrt(2);
        }

        player.MoveRelative(movement.x * player.move_speed,
                            movement.y * player.move_speed);
        break;
    }

    // Draw Stuff Here
    XClearWindow(display.display(), window.window());
    shape.draw_rectangle(e.x - 5, e.y - 5, 10, 10, true);
  }

  return 0;
}