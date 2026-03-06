#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace config {
  inline std::string ASSETS_DIR = "flappy-bird-assets/sprites/";
  inline int BIRD_RADIUS = 15;
  inline sf::Vector2f GRAVITY({0.f, 100.f});
  inline sf::Vector2f BASE_BIRD_VELOCITY({0.f, 0.f});
  inline sf::Vector2f BIRD_JUMP({0.f, -200.f});
};