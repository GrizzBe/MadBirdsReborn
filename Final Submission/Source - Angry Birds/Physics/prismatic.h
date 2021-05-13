#ifndef __PRISMATIC_H__
#define __PRISMATIC_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   prismatic.h
//  Description :   Box2D prismatic rail object.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "gameObject.h"
 // Implementation 
class prismatic
{
public:
	prismatic(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, sf::Texture* _railTexture, b2World* _world, bool _destructable);
	~prismatic();

	void Update(float _dT);
	void Draw(sf::RenderWindow& _window);
private:
	b2PrismaticJoint* m_Joint;
	gameObject* m_Object;
	gameObject* m_Ground;
	sf::Sprite* m_Rail;
};
#endif
