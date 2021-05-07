#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   menuScene.h
//  Description :   Menu scene containing buttons to select levels and quit game.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <SFML/Graphics.hpp>
 // Local Includes 
#include "button.h"
 // Implementation 
class menuScene
{
public:
	menuScene();
	~menuScene();

	void MainLoop(sf::RenderWindow& _window);
	void Update(sf::RenderWindow& _window, float _dT);
	void Render(sf::RenderWindow& _window);
	void LoadTextures();

private:
	sf::Sprite* m_MenuBG;

	sf::Texture* m_MenuBGTexture;
	sf::Texture* m_Button1Texture;
	sf::Texture* m_Button2Texture;
	sf::Texture* m_Button3Texture;
	sf::Texture* m_Button4Texture;
	sf::Texture* m_ButtonQTexture;

	std::vector<button*> m_Buttons;
};

#endif