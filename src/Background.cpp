#include <Background.hpp>

Background::Background(const sf::Texture& background_texture) : background(background_texture) {}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  states.texture = &background.getTexture();

  target.draw(background, states);
}