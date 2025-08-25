#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "../Engine/Game.hpp"

namespace MySFMLEngine {
	class SplashState : public State { // Inherit from State base class
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;

	};
}