#include <sstream>
#include <iostream>

#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

namespace MySFMLEngine {
	SplashState::SplashState(GameDataRef data) : _data(data) { // member initializer list

	}

	void SplashState::Init() {
		_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
	
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));

		// Center the background
		_background.setPosition((SCREEN_WIDTH / 2) - (_background.getGlobalBounds().width / 2), 
			(SCREEN_HEIGHT / 2) - (_background.getGlobalBounds().height / 2));
	}

	void SplashState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt) {
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			// Switch to Main Menu 
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw(float dt) {
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}
}