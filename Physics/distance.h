#ifndef __DISTANCE_H__
#define __DISTANCE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   distance.h
//  Description :   Box2D distance joint.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "gameObject.h"
 // Implementation 
class distance
{
public:
	distance(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, sf::Texture* _railTexture, sf::Texture* _groundTexture, b2World* _world);
	~distance();

	void Update(float _dT);
	void Draw(sf::RenderWindow& _window);
private:
	b2DistanceJoint* m_Joint;
	gameObject* m_Object;
	gameObject* m_Ground;
	sf::Sprite* m_Beam;
};

#endif