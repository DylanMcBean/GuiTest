#include "entity.hpp"

void Entity::Move(int new_x, int new_y) {
  x = new_x;
  y = new_y;
}

void Entity::MoveRelative(int rel_x, int rel_y) {
  x += rel_x;
  y += rel_y;
}