#include "gaem.hpp"

#define DELTA 0.1

int main(int argc, char** argv)
{
    sf::RenderWindow appWindow(sf::VideoMode(WIDTH,HEIGHT,32), "App");
    Game gaem (appWindow);
    sf::Clock timer; // start the clock
    sf::Time delta = sf::seconds(DELTA);
    gaem.randomState();
    while (appWindow.isOpen()) {
        sf::Event appEvent;
        while (appWindow.pollEvent(appEvent)) {
            if (appEvent.type == sf::Event::Closed) appWindow.close();
        }
        sf::Time t = timer.getElapsedTime(); 
        if (t > delta) {
            gaem.update(appWindow);
            gaem.nextState();
            timer.restart();
            appWindow.display();
        }
    }

    return 0; 
}