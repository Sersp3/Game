#include <View.hpp>

View::View(sf::Vector2u window_size) : view(sf::FloatRect({0.f, 0.f}, config::VIEW_PARAMS)) {
  UpdateView(window_size);
}

void View::UpdateView(sf::Vector2u window_size) {
  float x = static_cast<float>(window_size.x);
  float y = static_cast<float>(window_size.y);
  float x0 = config::VIEW_PARAMS.x;
  float y0 = config::VIEW_PARAMS.y;

  if (y0 * x >= y * x0) {
    float new_x = x0 * y / y0;
    float width_ratio = new_x / x; 
    view.setViewport(sf::FloatRect({(1.f - width_ratio) / 2.f, 0.f}, {width_ratio, 1.f}));
  } else {
    float new_y = x * y0 / x0;
    float height_ratio = new_y / y;
    view.setViewport(sf::FloatRect({0.f, (1.f - height_ratio) / 2.f}, {1.f, height_ratio}));
  }
}

void View::Reset() {
  // view.setSize(config::VIEW_PARAMS);
  view.setCenter(config::VIEW_PARAMS * float(0.5));
}

void View::Move(sf::Time delta_time) {
  view.move(config::BASE_VIEW_VELOCITY * delta_time.asSeconds());
}

const sf::View& View::GetView() {
  return view;
}