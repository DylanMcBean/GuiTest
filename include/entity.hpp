#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
 public:
  int x, y;

  Entity(int x = 0, int y = 0) : x(x), y(y) {}
  virtual ~Entity() {}

  void Move(int new_x, int new_y);
  void MoveRelative(int rel_x, int rel_y);
};

#endif  // ENTITY_HPP