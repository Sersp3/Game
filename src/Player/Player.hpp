#pragma once

#include <SFML/Graphics.hpp>
#include <Config.hpp>

class Player : public sf::Drawable, public sf::Transformable {
 public:
  Player(const sf::Texture& texture);
         
  void Update(sf::Time dt);

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  sf::Sprite model;
  float speed = config::PLAYER_SPEED;
};