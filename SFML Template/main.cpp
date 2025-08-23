// Make sure SFML is installed and the include path is set up correctly in your project properties.
// In Visual Studio, right-click your project > Properties > C/C++ > General > Additional Include Directories.
// Add the path to your SFML 'include' folder, e.g., C:\SFML\include

#include <iostream>

#include "Game.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main() {
    MySFMLEngine::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "SFML Starter");
    return EXIT_SUCCESS;
}
