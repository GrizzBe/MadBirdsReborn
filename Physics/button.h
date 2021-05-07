#ifndef __BUTTON_H__
#define __BUTTON_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   button.h
//  Description :   Button which can be clicked on to call a function.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <SFML/Graphics.hpp>
#include <iostream>
 // Local Includes 
#include "scene1.h"
#include "scene2.h"
 // Implementation 
enum class buttonFunction
{
	quitGame,
	level1,
	level2,
	level3,
	level4,
};

class button
{
public:
	button(sf::Texture* _texture, sf::Vector2f _pos, bool _enabled, buttonFunction _function);
	~button();
	bool IsMouseIntersecting(sf::RenderWindow& _window);
	void Activate(sf::RenderWindow& _window);
	sf::Sprite* GetSprite();
private:
	buttonFunction m_Function;
	sf::Sprite* m_Sprite;
	bool m_bIsEnabled;
};

#endif __BUTTON_H__