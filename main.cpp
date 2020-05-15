#include "gaem.hpp"
#include <iostream>

#define DELTA 0.005

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
            switch(appEvent.type) {
                case sf::Event::Closed:
                    appWindow.close();
                    break;
                case sf::Event::KeyPressed:
                    if (appEvent.key.code == sf::Keyboard::R) gaem.randomState();
                    if (appEvent.key.code == sf::Keyboard::Q) appWindow.close();
                    break;
                default:
                    break;
            }
            // if (appEvent.type == sf::Event::Closed) appWindow.close();
        }
        sf::Time t = timer.getElapsedTime(); 
        if (t > delta) {
            gaem.update(appWindow);
            gaem.nextState();
            // std::cout << t.asMicroseconds() << "\n";
            timer.restart();
            appWindow.display();
            
        }
    }

    return 0; 
}