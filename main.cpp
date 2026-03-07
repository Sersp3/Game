#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <AssetManager/AssetManager.hpp>
#include <Player/Player.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(config::WINDOW_RESOLUTION), "Game");
  AssetManager assets;
  assets.SetTexture("player", "assets/Mushroom/Mushroom without VFX/Mushroom-Idle.png");
  Player player(assets.GetTexture("player"));

  sf::Clock timer;
  while (window.isOpen()) {
    sf::Time dt = timer.restart();

    while (const std::optional<sf::Event> event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    player.Update(dt);
    window.clear();
    window.draw(player);
    window.display();
  }
}