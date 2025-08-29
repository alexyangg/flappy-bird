#include "Land.hpp"
#include "../DEFINITIONS.hpp"

namespace MySFMLEngine {
	Land::Land(GameDataRef data) : _data(data) {
		sf::Sprite sprite(_data->assets.GetTexture("Land"));
		sf::Sprite sprite2(_data->assets.GetTexture("Land"));

		sprite.setPosition(0, _data->window.getSize().y - sprite.getLocalBounds().height);
		sprite2.setPosition(sprite.getLocalBounds().width, _data->window.getSize().y - sprite.getLocalBounds().height);

		_landSprites.push_back(sprite);
		_landSprites.push_back(sprite2);
	}

	void Land::MoveLand(float dt) {
		for (unsigned short int i = 0; i < _landSprites.size(); i++) {
			float movement = PIPE_MOVEMENT_SPEED * dt;
			_landSprites[i].move(-movement, 0);

			if (_landSprites[i].getPosition().x < 0 - _landSprites[i].getGlobalBounds().width) {
				// If land is completely off the screen, move it to the right of the other land sprite
				sf::Vector2f position(_data->window.getSize().x, _landSprites[i].getPosition().y);

				_landSprites[i].setPosition(position);
			}
		}
	}

	void Land::DrawLand() {
		for (unsigned short int i = 0; i < _landSprites.size(); i++) {
			_data->window.draw(_landSprites[i]);
		}
	}
}