#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "../Engine/Game.hpp"

namespace MySFMLEngine {
	class Pipe {
	public:
		Pipe(GameDataRef data);

		void DrawPipes();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
	};
}