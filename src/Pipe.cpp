#include <Pipe.hpp>

Pipe::Pipe(const sf::Texture& pipe_texture, float gap_y, float pos_y) : top_pipe({config::PIPE_WIDTH, pos_y}), bottom_pipe({config::PIPE_WIDTH, config::VIEW_PARAMS.y - gap_y - pos_y}) {
  bottom_pipe.setTexture(&pipe_texture);
  bottom_pipe.move({0, gap_y + pos_y});

  top_pipe.setTexture(&pipe_texture);
  top_pipe.move({config::PIPE_WIDTH / 2, pos_y / 2});
  top_pipe.setOrigin({config::PIPE_WIDTH / 2, pos_y / 2});
  top_pipe.setScale({-1, -1});
}

sf::FloatRect Pipe::GetTopPipeGlobalBound() const {
  return getTransform().transformRect(top_pipe.getGlobalBounds());
}

sf::FloatRect Pipe::GetBottomPipeGlobalBound() const {
  return getTransform().transformRect(bottom_pipe.getGlobalBounds());
}

void Pipe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(top_pipe, states);
  target.draw(bottom_pipe, states);
}