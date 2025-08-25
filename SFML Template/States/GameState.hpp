#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "../Engine/Game.hpp"
#include "../GameObjects/Pipe.hpp"

namespace MySFMLEngine {
	class GameState : public State { // Inherit from State base class
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		Pipe* pipe;
	};
}