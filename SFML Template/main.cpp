// Make sure SFML is installed and the include path is set up correctly in your project properties.
// In Visual Studio, right-click your project > Properties > C/C++ > General > Additional Include Directories.
// Add the path to your SFML 'include' folder, e.g., C:\SFML\include

#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Window");

    while (window.isOpen())
    {
        // handle events

        // update game logic

        // draw
        window.clear();

        // draw SFML objects

        window.display();
    }
       
    return EXIT_SUCCESS;

}
