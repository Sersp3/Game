#include <AssetManager/AssetManager.hpp>

void AssetManager::SetTexture(const std::string& name, const std::string& path) {
  sf::Texture texture;

  if (!texture.loadFromFile(path)) {
    throw std::runtime_error("Unsuccesful import texture " + path + "\n");
  } else {
    FromStringToTexture[name] = std::move(texture);
  }
}

void AssetManager::SetSound(const std::string& name, const std::string& path) {
  sf::SoundBuffer sound;

  if (!sound.loadFromFile(path)) {
    throw std::runtime_error("Unsuccesful import sound " + path + "\n");
  } else {
    FromStringToSound[name] = std::move(sound);
  }
}

void AssetManager::SetFont(const std::string& name, const std::string& path) {
  sf::Font font;

  if (!font.openFromFile(path)) {
    throw std::runtime_error("Unsuccesful import font " + path + "\n");
  } else {
    FromStringToFont[name] = std::move(font);
  }
}

const sf::Texture& AssetManager::GetTexture(const std::string& name) const {
  if (!FromStringToTexture.contains(name)) {
		throw std::runtime_error("Unsuccesful get texture" + name);
  }
  return FromStringToTexture.at(name);
}

const sf::SoundBuffer& AssetManager::GetSound(const std::string& name) const {
  if (!FromStringToSound.contains(name)) {
		throw std::runtime_error("Unsuccesful get sound" + name);
  }
  return FromStringToSound.at(name);
}

const sf::Font& AssetManager::GetFont(const std::string& name) const {
  if (!FromStringToFont.contains(name)) {
		throw std::runtime_error("Unsuccesful get font" + name);
  }
  return FromStringToFont.at(name);
}