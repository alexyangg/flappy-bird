// Make sure SFML is installed and the include path is set up correctly in your project properties.
// In Visual Studio, right-click your project > Properties > C/C++ > General > Additional Include Directories.
// Add the path to your SFML 'include' folder, e.g., C:\SFML\include

#include <iostream>

#include "Game.hpp"
#include "DEFINITIONS.hpp"

int main() {
    MySFMLEngine::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    return EXIT_SUCCESS;
}
