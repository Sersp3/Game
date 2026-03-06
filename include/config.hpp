#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace config {
  inline std::string ASSETS_DIR = "flappy-bird-assets/sprites/";
  inline int BIRD_RADIUS = 16;
  inline sf::Vector2f GRAVITY({0.f, 512.f});
  inline sf::Vector2f BASE_BIRD_VELOCITY({128.f, 0.f});
  inline sf::Vector2f BASE_VIEW_VELOCITY({128.f, 0.f});
  inline sf::Vector2f BIRD_JUMP({0.f, -512.f});
  inline sf::Vector2f VIEW_PARAMS({1024, 512});
  inline float BIRD_VELOCITY_Y_BOUND = 256.f;
  inline sf::Vector2f BIRD_START({256, 256});
};