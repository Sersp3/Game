#include <Bird.hpp>
#include <Background.hpp>
#include <iostream>

int main() {
  sf::Texture bird_texture(config::ASSETS_DIR + "yellowbird-midflap.png");
  sf::Texture background_texture(config::ASSETS_DIR + "background-day.png");
  background_texture.setRepeated(true);

  sf::RenderWindow window(sf::VideoMode({1024, 512}), "Hello");
  sf::View view(sf::FloatRect({0.f, 0.f}, config::VIEW_PARAMS));
  window.setView(view);

  Bird bird(bird_texture, {256.f, 256.f});
  Background background(background_texture, window.getSize());

  sf::Clock timer;
  while (window.isOpen()) {
    sf::Time delta_time = timer.restart();

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      if (const sf::Event::KeyPressed* key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->scancode == sf::Keyboard::Scancode::Space) {
          bird.Jump();
        }
      }
    }

    bird.Move(delta_time);
    
    timer.reset();
    timer.start();
    
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(bird);
    window.display();

  }

  return 0;
}