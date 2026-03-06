#include <Bird.hpp>

Bird::Bird(const sf::Texture& bird_texture, sf::Vector2f position) {
  setPosition(position);
  bird.setRadius(config::BIRD_RADIUS);
  setOrigin({config::BIRD_RADIUS, config::BIRD_RADIUS});
  bird.setTexture(&bird_texture);
}

void Bird::Move(sf::Time delta_time) {
  move(velocity * delta_time.asSeconds());
  if (sf::Vector2f() != velocity) {
    setRotation(velocity.angle());
  }
  velocity += acceleration * delta_time.asSeconds();
}

void Bird::Jump() {
  velocity += config::BIRD_JUMP;
}

void Bird::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  states.texture = bird.getTexture();

  target.draw(bird, states);
}