#include <Bird.hpp>
#include <Background.hpp>
#include <View.hpp>
#include <iostream>
#include <Pipe.hpp>

int main() {
  sf::Texture pipe_texture(config::ASSETS_DIR + "pipe-green.png");
  sf::Texture bird_texture(config::ASSETS_DIR + "yellowbird-midflap.png");
  sf::Texture background_texture(config::ASSETS_DIR + "background-day.png");
  background_texture.setRepeated(true);

  sf::RenderWindow window(sf::VideoMode({1024, 512}), "Hello");
  View view(window.getSize());
  window.setView(view.GetView());

  Pipe pipe(pipe_texture, 128, 64);
  Bird bird(bird_texture, config::BIRD_START);
  Background background(background_texture, window.getSize());

  bird.GetGlobalBounds().position.x;

  sf::Clock timer;
  while (window.isOpen()) {
    sf::Time delta_time = timer.restart();

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      if (event->is<sf::Event::Resized>()) {
        view.UpdateView(window.getSize());
      }

      if (const sf::Event::KeyPressed* key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->scancode == sf::Keyboard::Scancode::Space) {
          bird.Jump();
        }

        if (key->scancode == sf::Keyboard::Scancode::R) {
          bird.Reset();
          view.Reset();
        }
      }
    }

    bird.Move(delta_time);
  
    view.Move(delta_time);
    pipe.move(config::BASE_BIRD_VELOCITY * (delta_time.asSeconds()));

    window.setView(view.GetView());
    
    
    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(bird);
    window.draw(pipe);
    window.display();

  }

  return 0;
}