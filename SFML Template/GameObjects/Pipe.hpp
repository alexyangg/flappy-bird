#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "../DEFINITIONS.hpp"
#include "../Engine/Game.hpp"

namespace MySFMLEngine {
	class Pipe {
	public:
		Pipe(GameDataRef data);

		void SpawnBottomPipe();
		void SpawnTopPipe();
		void SpawnInvisiblePipe(); // For collision detection
		void MovePipes(float dt);
		void DrawPipes();
		void RandomizePipeOffset();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;

		int _landHeight;
		int _pipeSpawnYOffset;
	};
}