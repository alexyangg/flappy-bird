#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace MySFMLEngine {
	struct GameData {
		StateMachine machine;
		AssetManager assets;
		InputManager input;
		sf::RenderWindow window;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game {
	public:
		Game(int width, int height, std::string title);

	private:
		const float dt = 1.0f / 60.0f; // frame rate, 60 fps
		sf::Clock _clock; // handles frame rate timing

		GameDataRef _data = std::make_shared<GameData>(); // shared pointer to game data
	
		void Run();
	};
}
