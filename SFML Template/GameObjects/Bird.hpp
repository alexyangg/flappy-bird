#pragma once

#include <SFML/Graphics.hpp>

#include "../DEFINITIONS.hpp"
#include "../Engine/Game.hpp"

namespace MySFMLEngine {
	class Bird {
	public:
		Bird(GameDataRef data);

		void Draw();

	private:
		GameDataRef _data;
		sf::Sprite _birdSprite;
	};
}