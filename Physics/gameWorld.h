#ifndef __GAME_WORLD_H__
#define __GAME_WORLD_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   gameWorld.h
//  Description :   Parent to all game scenes.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <SFML/Graphics.hpp>
#include <box2d.h>
#include <vector>
 // Local Includes 
#include "ContactListener.h"
#include "gameObject.h"
#include "bird.h"
#include "birdTire.h"
#include "birdSpin.h"
#include "birdQue.h"
#include "Chain.h"
#include "distance.h"
#include "seesaw.h"
#include "prismatic.h"
#include "victim.h"
 // Implementation 
enum class birdType
{
	basicBird,
	tireBird,
	spinBird,
	queBird,
};

class gameWorld
{
public:
	gameWorld();
	virtual ~gameWorld();

	virtual bool MainLoop(sf::RenderWindow& _window);
	virtual void Update(float _dT);
	virtual void Render(sf::RenderWindow& _window);
	virtual bool RestartCheck(float _dT, b2World& _world);
	virtual void LoadTextures();
	virtual void AddBird(birdType _type, b2World& _world);
	virtual void DestroyBox2DObjects();
	virtual void LaunchBird(sf::RenderWindow& _window);
	virtual b2Vec2 CalculateForce(sf::RenderWindow& _window);

	virtual void GenerateLevel(b2World& _world);
protected:
	// Restart check
	bool m_bShowMessage;
	bool m_bWinning;
	float m_fFinishedTimer;
	sf::Sprite* m_WinLossMessage;

	// Bird launching variables
	sf::Sprite* m_AimingArrow;
	bool m_bPullFlag;
	sf::Vector2i m_DragOrigin;
	float m_fForceMult;
	float m_fForceMax;

	ContactListener* m_contactList;

	std::vector<bird*>::iterator m_it; // Keeps track of selected bird
	bird* m_SelectedBird;

	// Object vectors
	std::vector<bird*> m_Birds;
	std::vector<victim*> m_Victims;
	std::vector<gameObject*> m_Blocks;

	// Joint objects
	Chain* m_Chain1;
	seesaw* m_Seesaw1;
	prismatic* m_Prismatic1;
	distance* m_Distance1;

	// Textures
	sf::Texture* m_WinTexture;
	sf::Texture* m_LossTexture;

	sf::Texture* m_BirdTexture;
	sf::Texture* m_BirdTireTexture;
	sf::Texture* m_BirdSpinTexture;
	sf::Texture* m_BirdQueTexture;
	sf::Texture* m_BirdQueTexture2;

	sf::Texture* m_VictimTexture;
	sf::Texture* m_VictimTexture2;

	sf::Texture* m_StrongBlockTexture;
	sf::Texture* m_WeakBlockTexture;

	sf::Texture* m_SeesawTexture;

	sf::Texture* m_WeightTexture;
	sf::Texture* m_RailTexture;
	sf::Texture* m_ChainTexture;

	sf::Texture* m_ArrowTexture;
};

#endif