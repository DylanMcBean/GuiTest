#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

class Player : public Entity {
 public:
  int move_speed = 5;

  Player(int x, int y) : Entity(x, y) {}
  ~Player() = default;
};

#endif  // PLAYER_HPP