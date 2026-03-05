#include <Bird.hpp>

Bird::Bird(const sf::Texture& bird_texture, sf::Vector2f position) {
  bird.setPosition(position);
  bird.setRadius(config::BIRD_RADIUS);
  bird.setTexture(&bird_texture);
}

void Bird::Move(sf::Time delta_time) {
  bird.move(velocity * delta_time.asSeconds());
  velocity += acceleration * delta_time.asSeconds();
}

void Bird::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  states.texture = bird.getTexture();

  target.draw(bird, states);
}