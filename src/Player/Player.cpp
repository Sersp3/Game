#include <Player/Player.hpp>

Player::Player(const sf::Texture& texture) : model(texture) {}

void Player::Update(sf::Time dt) {
  move(sf::Vector2f({100.f, 0.f}) * dt.asSeconds());
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  target.draw(model, states);
}