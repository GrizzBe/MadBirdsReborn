// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   menuScene.cpp
//  Description :   Menu scene containing buttons to select levels and quit game.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // This Include 
#include "menuScene.h"
 // Implementation 
menuScene::menuScene()
{
    m_MenuBG = 0;
    m_MenuBGTexture  = 0;
    m_Button1Texture = 0;
    m_Button2Texture = 0;
    m_Button3Texture = 0;
    m_Button4Texture = 0;
    m_ButtonQTexture = 0;
}

menuScene::~menuScene()
{
    if (m_MenuBGTexture != nullptr)
    {
        delete m_MenuBGTexture;
        m_MenuBGTexture = 0;
    }
    if (m_Button1Texture != nullptr)
    {
        delete m_Button1Texture;
        m_Button1Texture = 0;
    }
    if (m_Button2Texture != nullptr)
    {
        delete m_Button2Texture;
        m_Button2Texture = 0;
    }
    if (m_Button3Texture != nullptr)
    {
        delete m_Button3Texture;
        m_Button3Texture = 0;
    }
    if (m_Button4Texture != nullptr)
    {
        delete m_Button4Texture;
        m_Button4Texture = 0;
    }
    if (m_ButtonQTexture != nullptr)
    {
        delete m_ButtonQTexture;
        m_ButtonQTexture = 0;
    }

    if (m_MenuBG != nullptr)
    {
        delete m_MenuBG;
        m_MenuBG = 0;
    }

    std::vector<button*>::iterator b_it = m_Buttons.begin();
    while (b_it != m_Buttons.end())
    {
        // Delete vector contents
        delete* b_it;
        b_it = m_Buttons.erase((b_it));
    }
    m_Buttons.clear();
}

/***********************
* MainLoop: Main loop which calls render and update functions.
* @author: William de Beer
* @parameter: Reference to render window
********************/
void menuScene::MainLoop(sf::RenderWindow& _window)
{
    LoadTextures();

    m_MenuBG = new sf::Sprite(*m_MenuBGTexture);

    m_Buttons.push_back(new button(m_Button1Texture, sf::Vector2f(600, 275), true, buttonFunction::level1));
    m_Buttons.push_back(new button(m_Button2Texture, sf::Vector2f(600, 375), true, buttonFunction::level2));
    m_Buttons.push_back(new button(m_Button3Texture, sf::Vector2f(600, 475), false, buttonFunction::level3));
    m_Buttons.push_back(new button(m_Button4Texture, sf::Vector2f(600, 575), false, buttonFunction::level4));
    m_Buttons.push_back(new button(m_ButtonQTexture, sf::Vector2f(600, 700), true, buttonFunction::quitGame));

    sf::Clock clock;
    while (_window.isOpen())
    {
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        Update(_window, deltaTime);
        Render(_window);
    }
}

/***********************
* Update: Updates all menu objects
* @author: William de Beer
* @parameter: Delta time and Reference to render window
********************/
void menuScene::Update(sf::RenderWindow& _window, float _dT)
{
    for (auto i : m_Buttons)
    {
        if (i->IsMouseIntersecting(_window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            i->Activate(_window);
        }
    }
}

/***********************
* Render: Render all objects in menu.
* @author: William de Beer
* @parameter: Reference to render window
********************/
void menuScene::Render(sf::RenderWindow& _window)
{
    _window.clear(sf::Color(228, 228, 228));

    _window.draw(*m_MenuBG);
    for (auto i : m_Buttons)
    {
        _window.draw(*i->GetSprite());
    }

    _window.display();
}

/***********************
* LoadTextures: Loads all texture use in menu from files.
* @author: William de Beer
********************/
void menuScene::LoadTextures()
{
    m_MenuBGTexture = new sf::Texture();
    if (!m_MenuBGTexture->loadFromFile("Assets/Menu/MenuBG.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_Button1Texture = new sf::Texture();
    if (!m_Button1Texture->loadFromFile("Assets/Menu/Button1.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_Button2Texture = new sf::Texture();
    if (!m_Button2Texture->loadFromFile("Assets/Menu/Button2.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_Button3Texture = new sf::Texture();
    if (!m_Button3Texture->loadFromFile("Assets/Menu/Button3.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_Button4Texture = new sf::Texture();
    if (!m_Button4Texture->loadFromFile("Assets/Menu/Button4.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_ButtonQTexture = new sf::Texture();
    if (!m_ButtonQTexture->loadFromFile("Assets/Menu/ButtonQ.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }
}
