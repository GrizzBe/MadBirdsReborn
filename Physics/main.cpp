// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   main.cpp
//  Description :   Main
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <box2d.h>
#include <SFML/Graphics.hpp>
 // Local Includes 
#include "menuScene.h"
 // Implementation 
int main()
{
    // Create and initialise window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Mad Birds");
    window->setFramerateLimit(60.0f);

    // Create menu
    menuScene* menu = new menuScene();
    menu->MainLoop(*window);
    // Destroy menu
    delete menu;
    menu = nullptr;

    // Destroy window
    delete window;
    window = nullptr;
    return 0;
}

