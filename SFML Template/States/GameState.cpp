#include <sstream>
#include <iostream>

#include "../DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"

namespace MySFMLEngine {
	GameState::GameState(GameDataRef data) : _data(data) { // member initializer list

	}

	void GameState::Init() {
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

		pipe = new Pipe(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	}

	void GameState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				//_data->window.close();
				_data->machine.AddState(StateRef(new GameOverState(_data)), true); // temporary
			}
		}
	}

	void GameState::Update(float dt) {

	}

	void GameState::Draw(float dt) {
		_data->window.clear();

		_data->window.draw(_background);
		pipe->DrawPipes();

		_data->window.display();
	}
}