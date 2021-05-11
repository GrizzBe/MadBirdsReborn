// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   birdSpin.cpp
//  Description :   Class for Spinning bird object which will gain a burst of torque after a delay, allow the bird to roll backwards.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // This Include 
#include "birdSpin.h"
 // Implementation 
birdSpin::birdSpin(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape)
	: bird(_pos, _scale, _rotation, _texture, _bodyType, _world, -1)
{
	float radius = m_Sprite->getTexture()->getSize().x * m_Sprite->getScale().x / 2;

	// Create fixture
	b2CircleShape newCircle;
	newCircle.m_p.Set(0.0f, 0.0f);
	newCircle.m_radius = radius * Utilities::MPP;

	m_FixtureDef = new b2FixtureDef();
	m_FixtureDef->shape = &newCircle;
	m_FixtureDef->density = 1.0f;
	m_FixtureDef->friction = 10.0f;
	m_FixtureDef->restitution = 0.05f;

	if (m_FixtureDef != nullptr)
	{
		// Disable bird to bird collision
		m_FixtureDef->filter.groupIndex = -2;
	}

	m_Body->CreateFixture(m_FixtureDef);

	m_SpinTimer = 0.0f;
}

birdSpin::~birdSpin()
{
}

/***********************
* Update: Update bird type.
* @author: William de Beer
* @parameter: Delta time
********************/
void birdSpin::Update(float _dT)
{
	bird::Update(_dT);

	if (m_bHasLaunched && !m_bActivated)
	{
		m_SpinTimer += _dT;
		if (m_SpinTimer >= 0.5f)
		{
			m_Body->ApplyTorque(-750.0f * _dT, true); // Apply spin
		}
		if (m_SpinTimer >= 3.0f)
		{
			m_bActivated = true; // Cease spin
		}
	}
}

