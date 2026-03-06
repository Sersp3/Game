#include <Game.hpp>
#include <random>

Game::Game(View v, Background b, Bird bi, sf::Texture* pipe_texture) : view(v), background(b), bird(bi), pipe_texture(pipe_texture) {
  Reset();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(background, states);
  for (size_t i = 0; i < pipes.size(); ++i) {
    target.draw(pipes[i], states);
  }
  target.draw(bird, states);
}

void Game::BirdJump() {
  bird.Jump();
}

void Game::Reset() {
  bird.Reset();
  view.Reset();
  pipes.clear();
  world_borders.setSize(view.GetView().getSize());
  world_borders.setPosition(view.GetView().getCenter());
  world_borders.move(config::VIEW_PARAMS * float(-0.5));
}

void Game::AddPipe(float x_shift) {
  static std::mt19937 gen(std::random_device{}());
  std::uniform_real_distribution<float> dist(0, config::VIEW_PARAMS.y - 128);


  pipes.push_back(Pipe(*pipe_texture, 128, dist(gen)));
  pipes[pipes.size() - 1].move({x_shift, 0});
}

bool Game::IsCollision() {
  sf::FloatRect bird_bound = bird.GetGlobalBounds();

  for (size_t i = 0; i < pipes.size(); ++i) {
    if (bird_bound.findIntersection(pipes[i].GetTopPipeGlobalBound())) {
      return true;
    }
    if (bird_bound.findIntersection(pipes[i].GetBottomPipeGlobalBound())) {
      return true;
    }
  }

  std::optional<sf::FloatRect> result = bird_bound.findIntersection(world_borders.getGlobalBounds());

  if (!world_borders.getGlobalBounds().contains(bird_bound.getCenter())) {
    return true;
  }

  return false;
}

void Game::Update(sf::Time delta_time) {
  bird.Move(delta_time);
  view.Move(delta_time);
  world_borders.move(delta_time.asSeconds() * config::BASE_VIEW_VELOCITY);
  
  if (IsCollision()) {
    Reset();
  }
}

void Game::Start() {
  sf::RenderWindow window(sf::VideoMode(config::BASE_WINDOW), "Flappy-bird");
  window.setView(view.GetView());

  sf::Clock timer;
  sf::Time pipe_cooldown = sf::seconds(config::PIPE_FREQUENCY);

  while (window.isOpen()) {
    sf::Time delta_time = timer.restart();
    pipe_cooldown += delta_time;

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
          Reset();
        }
      }
    }

    if (pipe_cooldown.asSeconds() > config::PIPE_FREQUENCY) {
      pipe_cooldown -= sf::seconds(config::PIPE_FREQUENCY);
      AddPipe(bird.getPosition().x + config::VIEW_PARAMS.x);
    }

    Update(delta_time);
    window.setView(view.GetView());
    window.clear(sf::Color::Black);
    window.draw(*this);
    window.display();
  }
}