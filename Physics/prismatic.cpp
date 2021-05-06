#include "prismatic.h"

prismatic::prismatic(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, sf::Texture* _railTexture, b2World* _world, bool _destructable)
{
	m_Ground = new gameObject(b2Vec2(0.0f,0.0f), sf::Vector2f(0.5f, 0.5f), 0.0f, _texture, b2_staticBody, _world, 1, false);
	m_Object = new gameObject(_pos, _scale * 1.0f, 0.0f, _texture, b2_dynamicBody, _world, 2, false);
	m_Object->SetLethal(true);

	b2PrismaticJointDef pjd;

	// Horizontal
	pjd.Initialize(m_Ground->GetBody(), m_Object->GetBody(), m_Object->GetBody()->GetPosition(), b2Vec2(1.0f, 0.0f));

	pjd.maxMotorForce = 10000.0f;
	pjd.enableMotor = false;
	pjd.lowerTranslation = 0.0f;
	pjd.upperTranslation = 10.0f;
	pjd.enableLimit = true;

	m_Rail = new sf::Sprite(*_railTexture);
	m_Rail->setPosition(_pos.x * Utilities::PPM, _pos.y * Utilities::PPM);
	m_Rail->setScale(abs(pjd.upperTranslation) * 2.0f * Utilities::MPP, 1.0f * Utilities::MPP);
	m_Rail->setOrigin(0.0f, _railTexture->getSize().y / 2);
	m_Joint = (b2PrismaticJoint*)_world->CreateJoint(&pjd);
}

prismatic::~prismatic()
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
	if (m_Rail != nullptr)
	{
		delete m_Rail;
		m_Rail = 0;
	}
}

void prismatic::Update(float _dT)
{
	m_Object->Update(_dT);
	m_Ground->Update(_dT);
}

void prismatic::Draw(sf::RenderWindow& _window)
{
	_window.draw(*m_Rail);
	_window.draw(*m_Object->GetSprite());
}
