#include <SFML/Graphics.hpp>
#include <array>

const std::string ASSETS_DIR = "flappy-bird-assets/sprites/";
const sf::Vector2f GRAVITY{0.f, 0.1};
const sf::Vector2f JUMP_GAIN{0.f, -10.f};
const sf::Vector2f VELOCITY_BOUND{5.f, 5.f};
const sf::Vector2f START_SPEED{0.f, 0.f};

class Bird {
 public:
  Bird() {
    std::string path = ASSETS_DIR + "bluebird-midflap.png";
    texture_bird.loadFromImage(sf::Image(path));
    bird.setRadius(15);
    bird.setTexture(&texture_bird);
    bird.setPosition({100, 50});
  }

  void Jump() {
    speed += JUMP_GAIN;
    NormalizeSpeed(); 
  }

  void Draw(sf::RenderWindow& window) {
    window.draw(bird);
  }

  void Update() {
    bird.move(speed);
    speed += acceleration;
    NormalizeSpeed();
  }

  void NormalizeSpeed() {
    speed.x = std::min(std::max(speed.x, -VELOCITY_BOUND.x), VELOCITY_BOUND.x);
    speed.y = std::min(std::max(speed.y, -VELOCITY_BOUND.y), VELOCITY_BOUND.y);
  }
  
 private:
  sf::Texture texture_bird;
  sf::CircleShape bird;
  sf::Vector2f speed{START_SPEED};
  sf::Vector2f acceleration{GRAVITY};
};

int main() { 
  sf::RenderWindow window(sf::VideoMode({2000, 400}), "Flappy bird");
  window.setFramerateLimit(60);
  sf::Texture background_texture(ASSETS_DIR + "background-day.png");
  background_texture.setRepeated(true);
  sf::Sprite background(background_texture, sf::IntRect({0, 0}, {2000, 400}));

  Bird player;

  while (window.isOpen()) {
    if (const std::optional<sf::Event> event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>()) {
        if (key_pressed->scancode == sf::Keyboard::Scancode::Space) {
          player.Jump();
        }
      }
    }

    player.Update();

    window.clear();
    window.draw(background);
    player.Draw(window);
    window.display();
  }
  return 0;
}