#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../DEFINITIONS.hpp"
#include "../Engine/Game.hpp"

namespace MySFMLEngine {
	class Bird {
	public:
		Bird(GameDataRef data);

		void Draw();
		void Animate(float dt);
		void Update(float dt);
		void Tap();

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite;
		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationIterator; // curr frame of animation

		sf::Clock _animationClock; // time since last frame change
		sf::Clock _movementClock; // time since last movement change

		int _birdState;

		float _rotation;
	};
}