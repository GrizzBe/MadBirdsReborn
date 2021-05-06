#include <box2d.h>
#include <SFML/Graphics.hpp>
#include "menuScene.h"


int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Mad Birds");
    window->setFramerateLimit(60.0f);

    menuScene* menu = new menuScene();
    menu->MainLoop(*window);
    delete menu;
    menu = nullptr;

    delete window;
    window = nullptr;
    return 0;
}

