#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace config {
  inline std::string ASSETS_DIR = "flappy-bird-assets/sprites/";
  inline int BIRD_RADIUS = 15;
  inline sf::Vector2f GRAVITY({0.f, 200.f});
  inline sf::Vector2f BASE_BIRD_VELOCITY({100.f, 0.f});
  inline sf::Vector2f BIRD_JUMP({0.f, -400.f});
  inline sf::Vector2f VIEW_PARAMS({1024, 512});
  inline float BIRD_ANGLE = 0.1;
};