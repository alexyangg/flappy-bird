#include <sstream>
#include <iostream>

#include "../DEFINITIONS.hpp"
#include "GameOverState.hpp"

namespace MySFMLEngine {
	GameOverState::GameOverState(GameDataRef data) : _data(data) { // member initializer list

	}

	void GameOverState::Init() {
		std::cout << "Game Over State" << std::endl;
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
	}

	void GameOverState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_data->window.close();
			}
		}
	}

	void GameOverState::Update(float dt) {

	}

	void GameOverState::Draw(float dt) {
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}
}