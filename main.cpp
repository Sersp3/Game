#include <SFML/Graphics.hpp>
#include <optional>

int main() {
  // Создаем окно. В 3.0 используем фигурные скобки для VideoMode
  sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.0: 2-Spaces Style");
  
  // Ограничиваем FPS, чтобы не перегружать Instruction Pointer
  window.setFramerateLimit(60);

  sf::CircleShape player(25.f);
  player.setFillColor(sf::Color::Blue);
  player.setPosition({400.f, 300.f});

  while (window.isOpen()) {
    // 1. СОБЫТИЙНЫЙ ЦИКЛ (для разовых действий и системных команд)
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      // Смена цвета по нажатию пробела (разовое событие)
      if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->code == sf::Keyboard::Key::Space) {
          player.setFillColor(sf::Color::Red);
        }
      }
    }
    
    // 2. REAL-TIME INPUT (для плавного движения)
    sf::Vector2f movement{0.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += 5.f;

    player.move(movement);

    // 3. ОТРИСОВКА
    window.clear(sf::Color::Black);
    window.draw(player);
    window.display();
  }

  return 0;
}