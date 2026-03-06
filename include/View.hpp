#pragma once

#include <SFML/Graphics.hpp>
#include <IMovable.hpp>

class View : public IMovable {
 public:
  View(sf::Vector2u);

  const sf::View& GetView();

  void Move(sf::Time delta_time);

  void Reset();

  void UpdateView(sf::Vector2u);
 private:
  sf::View view;
  sf::Vector2f velocity = config::BASE_VIEW_VELOCITY;
};