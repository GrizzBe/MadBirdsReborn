// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   bird.cpp
//  Description :   Class for basic bird object and parent to other types of bird objects.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // This Includes 
#include "bird.h"
 // Implementation 
bird::bird(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape)
	: gameObject(_pos, _scale, _rotation, _texture, _bodyType, _world, _shape, false)
{
	m_bActivated = false;
	m_bIsSelected = false;
	m_bHasLaunched = false;

	if (m_FixtureDef != nullptr)
	{
		// Disable bird to bird collision
		b2Filter filter;
		filter.groupIndex = -2;
		m_Body->GetFixtureList()->SetFilterData(filter);
	}
}

bird::~bird()
{
}

void bird::Update(float _dT)
{
	if (!m_bHasLaunched) // Make sure bird does not recieve damage until launched.
	{
		m_Durability = m_MaxDurability;
	}
	gameObject::Update(_dT);
}

