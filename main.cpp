#include "include/Bird.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 800}), "Hello");
  Bird bird({50.f, 50.f});

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    window.clear(sf::Color::Red);
    window.draw(bird);
    window.display();
  }

  return 0;
}