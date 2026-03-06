#include <Bird.hpp>
#include <Background.hpp>

int main() {
  sf::Texture bird_texture(config::ASSETS_DIR + "yellowbird-midflap.png");
  sf::Texture background_texture(config::ASSETS_DIR + "background-day.png");
  background_texture.setRepeated(true);

  sf::RenderWindow window(sf::VideoMode({800, 800}), "Hello");
  Bird bird(bird_texture, {50.f, 50.f});
  Background background(background_texture);

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