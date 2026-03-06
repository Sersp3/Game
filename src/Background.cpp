#include <Background.hpp>

Background::Background(const sf::Texture& background_texture, sf::Vector2u window_size) : background(background_texture) {
  background.setTextureRect(sf::IntRect({0, 0}, {window_size.x, window_size.y}));
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  states.texture = &background.getTexture();

  target.draw(background, states);
}