#ifndef __GAME_WORLD_H__
#define __GAME_WORLD_H__

#include "gameObject.h"

#include <SFML/Graphics.hpp>
#include <box2d.h>
#include <vector>
#include "ContactListener.h"

#include "bird.h"
#include "birdTire.h"
#include "birdSpin.h"
#include "birdQue.h"

#include "Chain.h"
#include "seesaw.h"
#include "prismatic.h"
#include "victim.h"

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

	virtual void MainLoop(sf::RenderWindow& _window);
	virtual void Update(float _dT);
	virtual void Render(sf::RenderWindow& _window);
	virtual void LoadTextures();
	virtual void AddBird(birdType _type, b2World& _world);
	virtual void DestroyBox2DObjects();
	virtual void LaunchBird(sf::RenderWindow& _window);
	virtual b2Vec2 CalculateForce(sf::RenderWindow& _window);

	virtual void GenerateLevel(b2World& _world);
protected:
	sf::Sprite* m_AimingArrow;

	//Bird launching variables
	bool m_bPullFlag;
	sf::Vector2i m_DragOrigin;
	float m_fForceMult;
	float m_fForceMax;



	ContactListener* m_contactList;

	std::vector<bird*>::iterator m_it;
	std::vector<bird*> m_Birds;
	std::vector<victim*> m_Victims;
	std::vector<gameObject*> m_Blocks;
	bird* m_SelectedBird;

	// Textures
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