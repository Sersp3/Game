#include <Bird.hpp>
#include <Background.hpp>
#include <View.hpp>
#include <iostream>
#include <Pipe.hpp>
#include <Game.hpp>

int main() {
  sf::Texture pipe_texture(config::ASSETS_DIR + "pipe-green.png");
  sf::Texture bird_texture(config::ASSETS_DIR + "yellowbird-midflap.png");
  sf::Texture background_texture(config::ASSETS_DIR + "background-day.png");
  background_texture.setRepeated(true);

  View view(config::BASE_WINDOW);
  Bird bird(bird_texture, config::BIRD_START);
  Background background(background_texture, config::BASE_WINDOW);

  Game game(view, background, bird, &pipe_texture);

  game.Start();

  return 0;
}