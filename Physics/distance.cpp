#include "distance.h"

distance::distance(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, sf::Texture* _railTexture, sf::Texture* _groundTexture, b2World* _world)
{
	// Grounded static object
	m_Ground = new gameObject(b2Vec2(_pos), sf::Vector2f(1.0f, 1.0f), 0.0f, _groundTexture, b2_staticBody, _world, 1, false);
	// Object on slider
	m_Object = new gameObject(_pos + b2Vec2(0.0f, -8.5f), _scale, 0.0f, _texture, b2_dynamicBody, _world, 2, false);
	m_Object->SetLethal(true);

	// Create joint
	b2DistanceJointDef djd;
	djd.Initialize(m_Ground->GetBody(), m_Object->GetBody(), m_Ground->GetBody()->GetPosition(), m_Object->GetBody()->GetPosition());


	m_Beam = new sf::Sprite(*_railTexture);
	m_Beam->setPosition(_pos.x * Utilities::PPM, _pos.y * Utilities::PPM);
	m_Beam->setScale(2.0f * djd.length * Utilities::MPP, 1.0f * Utilities::MPP);
	m_Beam->setOrigin(0.0f, _railTexture->getSize().y / 2.0f);

	djd.collideConnected = true;
	m_Joint = (b2DistanceJoint*)_world->CreateJoint(&djd);
}

distance::~distance()
{
	if (m_Ground != nullptr)
	{
		delete m_Ground;
		m_Ground = 0;
	}
	if (m_Object != nullptr)
	{
		delete m_Object;
		m_Object = 0;
	}
	if (m_Beam != nullptr)
	{
		delete m_Beam;
		m_Beam = 0;
	}
}

/***********************
* Update: Update objects.
* @author: William de Beer
* @parameter: Delta time
********************/
void distance::Update(float _dT)
{
	b2Vec2 posDiff = m_Ground->GetBody()->GetPosition() - m_Object->GetBody()->GetPosition();

	float angle = atan(posDiff.y / posDiff.x) * 180.0f / 3.14f;
	if (posDiff.x < 0)
	{
		m_Beam->setRotation(angle);
	}
	else
	{
		m_Beam->setRotation(angle + 180.0f);
	}

	m_Object->Update(_dT);
	m_Ground->Update(_dT);
}

/***********************
* Draw: Draw objects.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void distance::Draw(sf::RenderWindow& _window)
{
	_window.draw(*m_Beam);
	_window.draw(*m_Ground->GetSprite());
	_window.draw(*m_Object->GetSprite());
}
