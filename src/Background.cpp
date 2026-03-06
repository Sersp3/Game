#include <Background.hpp>

Background::Background(const sf::Texture& background_texture, sf::Vector2u window_size) : background(background_texture) {
  UpdateWindowResize(window_size);
}

void Background::UpdateWindowResize(sf::Vector2u window_size) {
  int x = static_cast<int>(window_size.x);
  int y = static_cast<int>(window_size.y);
  background.setTextureRect(sf::IntRect({0, 0}, {x, y}));
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  states.texture = &background.getTexture();

  target.draw(background, states);
}