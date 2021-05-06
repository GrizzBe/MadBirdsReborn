#include "seesaw.h"

seesaw::seesaw(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, sf::Texture* _pivotTexture, b2World* _world, bool _destructable)
{
	m_Ground = new gameObject(_pos, sf::Vector2f(1.0f, 1.0f), 0.0f, _texture, b2_staticBody, _world, 2, false);
	m_Object = new gameObject(_pos, _scale, 0.0f, _texture, b2_dynamicBody, _world, 1, false);

	b2RevoluteJointDef rjd;
	rjd.Initialize(m_Ground->GetBody(), m_Object->GetBody(), m_Object->GetBody()->GetWorldCenter());

	m_Joint = (b2RevoluteJoint*)_world->CreateJoint(&rjd);
}

seesaw::~seesaw()
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
}

void seesaw::Update(float _dT)
{
	m_Object->Update(_dT);
	m_Ground->Update(_dT);
}

void seesaw::Draw(sf::RenderWindow& _window)
{
	_window.draw(*m_Ground->GetSprite());
	_window.draw(*m_Object->GetSprite());
}
