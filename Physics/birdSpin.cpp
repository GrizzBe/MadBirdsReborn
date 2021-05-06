#include "birdSpin.h"
birdSpin::birdSpin(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape)
	: bird(_pos, _scale, _rotation, _texture, _bodyType, _world, -1)
{
	float radius = m_Sprite->getTexture()->getSize().x * m_Sprite->getScale().x / 2;

	b2CircleShape newCircle;
	newCircle.m_p.Set(0.0f, 0.0f);
	newCircle.m_radius = radius * Utilities::MPP;

	m_FixtureDef = new b2FixtureDef();
	m_FixtureDef->shape = &newCircle;
	m_FixtureDef->density = 1.0f;
	m_FixtureDef->friction = 1.0f;
	m_FixtureDef->restitution = 0.05f;

	m_Body->CreateFixture(m_FixtureDef);

	m_SpinTimer = 0.0f;
}

birdSpin::~birdSpin()
{
}

void birdSpin::Update(float _dT)
{
	bird::Update(_dT);

	if (m_bHasLaunched && !m_bActivated)
	{
		m_SpinTimer += _dT;
		if (m_SpinTimer >= 0.5f)
		{
			m_Body->ApplyTorque(-500.0f * _dT, true);
		}
		if (m_SpinTimer >= 3.0f)
		{
			m_bActivated = true;
		}
	}
}

