#ifndef __CHAIN_H__
#define __CHAIN_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Chain.h
//  Description :   Box2D chain.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "gameObject.h"
 // Implementation 
class Chain
{
public:
	Chain(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, b2World* _world, bool _destructable);
	~Chain();

	void Update(float _dT);
	void Draw(sf::RenderWindow& _window);
private:
	std::vector<gameObject*> m_ChainLinks;
};
#endif
