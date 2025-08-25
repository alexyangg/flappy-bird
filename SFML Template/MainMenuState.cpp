#include <sstream>
#include <iostream>

#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

namespace MySFMLEngine {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data) { // member initializer list

	}

	void MainMenuState::Init() {
		_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		// Center title in x axis
		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), 
			_title.getGlobalBounds().height);

		// Center play button in x and y axis
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
	}

	void MainMenuState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_playButton,
				sf::Mouse::Left, 
				_data->window)) {
				std::cout << "Go to Game State" << std::endl;
				// _data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::Update(float dt) {
		// No updates needed for static main menu
	}

	void MainMenuState::Draw(float dt) {
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);

		_data->window.display();
	}
}