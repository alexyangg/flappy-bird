#include "Bird.hpp"

namespace MySFMLEngine {
	Bird::Bird(GameDataRef data) : _data(data) {
	
		_animationIterator = 0;

		for (int i = 1; i <= 4; i++) {
			_animationFrames.push_back(_data->assets.GetTexture("Bird Frame " + std::to_string(i)));
		}

		_birdSprite.setTexture(_animationFrames[_animationIterator]);
		
	}

	void Bird::Draw() {
		_data->window.draw(_birdSprite);
	}

	void Bird::Animate(float dt) {
		if (_animationClock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size()) {
			if (_animationIterator < _animationFrames.size() - 1) {
				_animationIterator++;
			}
			else {
				_animationIterator = 0;
			}

			_birdSprite.setTexture(_animationFrames[_animationIterator]);

			_animationClock.restart();
		}
	}
}