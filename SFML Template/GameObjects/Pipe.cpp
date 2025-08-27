#include "Pipe.hpp"
#include <iostream>

namespace MySFMLEngine {
	Pipe::Pipe(GameDataRef data) : _data(data) {}

	void Pipe::SpawnBottomPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		// spawns at bottom right corner of the screen
		sprite.setPosition(_data->window.getSize().x,
			_data->window.getSize().y - sprite.getGlobalBounds().height
		);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));

		// spawns at top right corner of the screen
		sprite.setPosition(_data->window.getSize().x, 0);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnInvisiblePipe() { // For collision detection
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		// spawns at bottom right corner of the screen
		sprite.setPosition(_data->window.getSize().x,
			_data->window.getSize().y - sprite.getGlobalBounds().height
		);
		sprite.setColor(sf::Color(0, 0, 0, 0)); // invisible

		pipeSprites.push_back(sprite);
	}

	void Pipe::MovePipes(float dt) {
		for (unsigned short int i = 0; i < pipeSprites.size();) {
			sf::Vector2f position = pipeSprites[i].getPosition();
			float pipeWidth = pipeSprites[i].getGlobalBounds().width;
			if (position.x < 0 - pipeWidth) { // 0 - pipeWidth ensures pipe is fully off-screen
				pipeSprites.erase(pipeSprites.begin() + i); // O(n) deletion, but okay for small number of pipes
			}
			else {
				float movement = PIPE_MOVEMENT_SPEED * dt;
				pipeSprites[i].move(-movement, 0);
				i++; // only increment if not erasing to prevent skipping next pipe
			}

			//std::cout << pipeSprites.size() << std::endl;
		}
	}

	void Pipe::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
			_data->window.draw(pipeSprites[i]);
		}
	}
}