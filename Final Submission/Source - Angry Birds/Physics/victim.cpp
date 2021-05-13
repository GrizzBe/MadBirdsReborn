// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   victim.cpp
//  Description :   Destructable enemy class.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // This Include 
#include "victim.h"
 // Implementation 
victim::victim(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, sf::Texture* _damagedTexture, b2BodyType _bodyType, b2World* _world, int _shape)
	: gameObject(_pos, _scale, _rotation, _texture, _bodyType, _world, _shape, false)
{
	m_MaxDurability = 15.0f;
	m_Durability = m_MaxDurability;
	m_bDestructable = true;
	m_texDamaged = _damagedTexture;
}

victim::~victim()
{
}

/***********************
* Update: Updates object.
* @author: William de Beer
* @parameter: Delta time
********************/
void victim::Update(float _dT)
{
	if (m_Durability < m_MaxDurability)
	{ // Damage state
		m_Sprite->setTexture(*m_texDamaged);
	}

	gameObject::Update(_dT);
}
