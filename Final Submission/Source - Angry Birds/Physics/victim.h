#ifndef __VICTIM_H_
#define __VICTIM_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   victim.h
//  Description :   Destructable enemy class.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
 // Local Includes 
 // This Include 
 // Static Variables 
 // Static Function Prototypes 
 // Implementation 
#include "gameObject.h"
class victim :
    public gameObject
{
public:
	victim(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, sf::Texture* _damagedTexture, b2BodyType _bodyType, b2World* _world, int _shape);
	virtual ~victim();

	virtual void Update(float _dT);
private:
	sf::Texture* m_texDamaged;
};

#endif