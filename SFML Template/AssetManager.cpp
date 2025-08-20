#include "AssetManager.hpp"

namespace MySFMLEngine {
	void AssetManager::LoadTexture(std::string name, std::string filePath) {
		sf::Texture tex;
		if (tex.loadFromFile(filePath)) {
			this->_textures[name] = tex;
		}
		else {
			throw std::runtime_error("Failed to load texture: " + filePath);
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name) {
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string filePath) {
		sf::Font font;
		if (font.loadFromFile(filePath)) {
			this->_fonts[name] = font;
		}
		else {
			throw std::runtime_error("Failed to load font: " + filePath);
		}
	}

	sf::Font& AssetManager::GetFont(std::string name) {
		return this->_fonts.at(name);
	}
}