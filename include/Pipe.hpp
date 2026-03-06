#include <SFML/Graphics.hpp>
#include <IMovable.hpp>

class Pipe : public sf::Drawable, public sf::Transformable {
 public:
  Pipe(const sf::Texture& pipe_texture, float gap_y, float pos_y);

  sf::FloatRect GetTopPipeGlobalBound() const;

  sf::FloatRect GetBottomPipeGlobalBound() const;

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  sf::RectangleShape top_pipe;
  sf::RectangleShape bottom_pipe;
};