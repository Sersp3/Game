#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>


class AssetManager {
 public:
  void SetTexture(const std::string& name, const std::string& path);

  void SetSound(const std::string& name, const std::string& path);

  void SetFont(const std::string& name, const std::string& path);

  const sf::Texture& GetTexture(const std::string& name) const;

  const sf::SoundBuffer& GetSound(const std::string& name) const;

  const sf::Font& GetFont(const std::string& name) const;

 private:
  std::map<std::string, sf::Texture> FromStringToTexture;
  std::map<std::string, sf::SoundBuffer> FromStringToSound;
  std::map<std::string, sf::Font> FromStringToFont;
};