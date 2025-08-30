#include "Bird.hpp"

namespace MySFMLEngine {
	Bird::Bird(GameDataRef data) : _data(data) {
	
		_animationIterator = 0;

		for (int i = 1; i <= 4; i++) {
			_animationFrames.push_back(_data->assets.GetTexture("Bird Frame " + std::to_string(i)));
		}

		_birdSprite.setTexture(_animationFrames[_animationIterator]);
		
		// Position bird in the center-left of the screen
		_birdSprite.setPosition((_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2), 
			(_data->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().height / 2));
	
		_birdState = BIRD_STATE_STILL;
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

	void Bird::Update(float dt) {
		if (_birdState == BIRD_STATE_FALLING) {
			_birdSprite.move(0, GRAVITY * dt);
		}
		else if (_birdState == BIRD_STATE_FLYING) {
			_birdSprite.move(0, -FLYING_SPEED * dt);
		}

		if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
			_birdState = BIRD_STATE_FALLING;
			_movementClock.restart();
		}
	}

	void Bird::Tap() {
		_movementClock.restart();
		_birdState = BIRD_STATE_FLYING;
	}
}