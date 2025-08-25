#include <sstream>
#include <iostream>

#include "DEFINITIONS.hpp"
#include "GameState.hpp"

namespace MySFMLEngine {
	GameState::GameState(GameDataRef data) : _data(data) { // member initializer list

	}

	void GameState::Init() {
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	}

	void GameState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_data->window.close();
			}
		}
	}

	void GameState::Update(float dt) {

	}

	void GameState::Draw(float dt) {
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}
}