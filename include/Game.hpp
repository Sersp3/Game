#pragma once

#include <Bird.hpp>
#include <Pipe.hpp>
#include <Background.hpp>
#include <View.hpp>
#include <vector>

class Game : public sf::Drawable {
 public:
  Game(View, Background, Bird, sf::Texture*);

  bool IsCollision();

  void Reset(); //bird.respawn, pipe.respawn
  
  void Start(); // Start game

  void BirdJump();

  void AddPipe(float x_shift);

  void Update(sf::Time delta_time);

  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 private:
  View view;
  Background background;
  std::vector<Pipe> pipes;
  Bird bird;
  sf::RectangleShape world_borders;
  sf::Texture* pipe_texture;
};