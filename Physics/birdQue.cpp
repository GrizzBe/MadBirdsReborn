// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   birdQue.cpp
//  Description :   Class for Quebird object which will gain a burst of speed in a direction after a second. Quebird == Cube bird... get it lol?
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // This Include 
#include "birdQue.h"
 // Implementation 
birdQue::birdQue(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, sf::Texture* _texture2, b2BodyType _bodyType, b2World* _world, int _shape)
	: bird(_pos, _scale, _rotation, _texture, _bodyType, _world, _shape)
{
	m_fDropTimer = 0;
	m_Texture2 = _texture2;
}

birdQue::~birdQue()
{
}

/***********************
* Update: Update bird type.
* @author: William de Beer
* @parameter: Delta time
********************/
void birdQue::Update(float _dT)
{
	bird::Update(_dT);

	if (m_bHasLaunched && !m_bActivated) // Quebird ability activation
	{
		m_fDropTimer += _dT; // Timer
		if (m_fDropTimer >= 0.75f)
		{
			m_bActivated = true;

			// Replace sprite
			m_Sprite->setTexture(*m_Texture2);

			// Destroy old fixture
			m_Body->DestroyFixture(m_Body->GetFixtureList()->GetNext());

			// Create new fixture
			b2PolygonShape* newBox = new b2PolygonShape();
			float width = 0.5f * m_Sprite->getTexture()->getSize().x * m_Sprite->getScale().x;
			float height = 0.5f * m_Sprite->getTexture()->getSize().y * m_Sprite->getScale().y;
			newBox->SetAsBox(width * Utilities::MPP, height * Utilities::MPP);

			m_FixtureDef = new b2FixtureDef();
			m_FixtureDef->shape = newBox;
			m_FixtureDef->density = 100.0f;
			m_FixtureDef->friction = 1.0f;
			m_FixtureDef->restitution = 0.0f;
			if (m_FixtureDef != nullptr)
			{
				m_FixtureDef->filter.groupIndex = -2;
			}

			m_Body->CreateFixture(m_FixtureDef);

			// Slam forwards and downwards.
			m_Body->SetLinearVelocity(b2Vec2(15.0f, 15.0f));
		}
	}
}
