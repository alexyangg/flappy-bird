#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "../Engine/Game.hpp"

namespace MySFMLEngine {
	class Land {
	public:
		Land(GameDataRef data);

		void MoveLand(float dt);
		void DrawLand();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _landSprites; // 2 land objects for seamless scrolling
	};
}