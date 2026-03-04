#include <SFML/Graphics.hpp>
#include <optional>

int main() {
  std::string SPRITE_DIR = "flappy-bird-assets/sprites/";

  sf::RenderWindow window(sf::VideoMode({800, 600}), "Flappy Bird");
  
  window.setFramerateLimit(60);

  sf::Texture bird_texture(SPRITE_DIR + "bluebird-midflap.png");

  sf::Sprite player(bird_texture);
  player.setPosition({400.f, 300.f});

  while (window.isOpen()) {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      // Смена цвета по нажатию пробела (разовое событие)
    }
    sf::Vector2f movement{0.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += 5.f;
    player.move(movement);
    
    // 2. REAL-TIME INPUT (для плавного движения)


    // 3. ОТРИСОВКА
    window.clear(sf::Color::Black);
    window.draw(player);
    window.display();
  }

  return 0;
}