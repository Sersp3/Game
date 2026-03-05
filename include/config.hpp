#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace config {
  inline std::string ASSETS_DIR = "flappy-bird-assets/sprites/";
  inline sf::Texture BIRD_TEXTURE("flappy-bird-assets/sprites/bluebird-midflap.png");
  inline sf::Vector2f GRAVITY({0.f, 1.f});
  inline sf::Vector2f BASE_VELOCITY({0.f, 0.f});
};