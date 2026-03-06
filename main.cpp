#include <Bird.hpp>
#include <Background.hpp>
#include <View.hpp>
#include <iostream>

int main() {
  sf::Texture bird_texture(config::ASSETS_DIR + "yellowbird-midflap.png");
  sf::Texture background_texture(config::ASSETS_DIR + "background-day.png");
  background_texture.setRepeated(true);

  sf::RenderWindow window(sf::VideoMode({1024, 512}), "Hello");
  View view(window.getSize());
  window.setView(view.GetView());

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
      }
    }

    bird.Move(delta_time);
  
    view.Move(delta_time);

    window.setView(view.GetView());
    
    
    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(bird);
    window.display();

  }

  return 0;
}