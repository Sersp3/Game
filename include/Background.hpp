#pragma once

#include <SFML/Graphics.hpp>
#include <config.hpp>

class Background : public sf::Drawable, public sf::Transformable {
 public:
  Background(const sf::Texture& background_texture);

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  sf::Sprite background;
};