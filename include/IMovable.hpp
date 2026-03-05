#pragma once

#include <SFML/Graphics.hpp>
#include <config.hpp>

class IMovable {
 public:
  virtual void Move(sf::Time delta_time) = 0;

  virtual ~IMovable() = default;
};