#include "../include/Bird.hpp"

Bird::Bird(sf::Vector2f position) {
  bird.setPosition(position);
  bird.setRadius(25);
  bird.setTexture(&config::BIRD_TEXTURE);
}

void Bird::Move(sf::Time delta_time) {
  bird.move(velocity * delta_time.asSeconds());
  velocity += acceleration * delta_time.asSeconds();
}

void Bird::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= bird.getTransform();

  states.texture = bird.getTexture();

  target.draw(bird, states);
}