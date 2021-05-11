// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   button.cpp
//  Description :   Button which can be clicked on to call a function.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // This Include 
#include "button.h"
 // Implementation 
button::button(sf::Texture* _texture, sf::Vector2f _pos, bool _enabled, buttonFunction _function)
{
	m_Sprite = new sf::Sprite(*_texture);
	m_Sprite->setScale(0.7f, 0.7f);
	m_Sprite->setOrigin((sf::Vector2f)_texture->getSize() / 2.0f);
	m_Sprite->setPosition(_pos);

	m_bIsEnabled = _enabled;
	m_Function = _function;
}

button::~button()
{
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = 0;
	}
}

/***********************
* IsMouseIntersecting: Check if mouse position is intersection with button bounds.
* @author: William de Beer
* @parameter: Reference to render window.
* @return: Boolean
********************/
bool button::IsMouseIntersecting(sf::RenderWindow& _window)
{
	if (m_bIsEnabled) // Check if button is enabled
	{
		if (m_Sprite->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(_window)))
		{
			m_Sprite->setColor(sf::Color(128, 255, 128)); // Set colour to green
			return true;
		}
		else
		{
			m_Sprite->setColor(sf::Color(255, 255, 255)); // Set colour to default
			return false;
		}
	}
	else
	{
		m_Sprite->setColor(sf::Color(128, 128, 128)); // Grey out
		return false;
	}
}

/***********************
* Activate: Use button function.
* @author: William de Beer
* @parameter: Reference to render window
********************/
void button::Activate(sf::RenderWindow& _window)
{
	bool resetGame = true;
	gameWorld* gW = nullptr;
	switch (m_Function)
	{
	case buttonFunction::level1: // Level 1
		while (resetGame)
		{
			gW = new scene1();
			resetGame = !gW->MainLoop(_window);

			delete gW;
			gW = 0;
		}
		break;
	case buttonFunction::level2: // Level 2
		while (resetGame)
		{
			gW = new scene2();
			resetGame = !gW->MainLoop(_window);

			delete gW;
			gW = 0;
		}
		break;
	case buttonFunction::level3: // Level 3
		while (resetGame)
		{
			gW = new scene3();
			resetGame = !gW->MainLoop(_window);

			delete gW;
			gW = 0;
		}
		break;
	case buttonFunction::level4: // Level 4
		std::cout << "Level does not exist." << std::endl;
		break;
	case buttonFunction::quitGame: // Quit game
		_window.close();
		break;
	default:
		std::cout << "Error actiavting button function." << std::endl;
		break;
	}
}

/***********************
* GetSprite: Get button sprite.
* @author: William de Beer
* @return: Pointer to sprite
********************/
sf::Sprite* button::GetSprite()
{
	return m_Sprite;
}

