#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "scene1.h"
#include "scene2.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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