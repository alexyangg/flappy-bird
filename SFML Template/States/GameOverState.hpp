#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "../Engine/Game.hpp"

namespace MySFMLEngine {
	class GameOverState : public State { // Inherit from State base class
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

	};
}