#pragma once

#include <SFML/Graphics.hpp>
#include <config.hpp>
#include <IMovable.hpp>

class Bird : public sf::Drawable, public sf::Transformable, public IMovable {
 public:
  Bird(const sf::Texture&, sf::Vector2f position);

  void Move(sf::Time delta_time) override;

  void Jump();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
 private:
  sf::CircleShape bird;
  sf::Vector2f velocity{config::BASE_BIRD_VELOCITY};
  sf::Vector2f acceleration{config::GRAVITY};
};