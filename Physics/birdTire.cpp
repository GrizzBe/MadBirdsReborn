#include "birdTire.h"
birdTire::birdTire(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape)
	: bird(_pos, _scale, _rotation, _texture, _bodyType, _world, _shape)
{
	m_MaxDurability = 5.0f;
	m_Durability = m_MaxDurability;
	m_fTimer = 0;
	m_StartScale = m_Sprite->getScale();
}

birdTire::~birdTire()
{
}

void birdTire::Update(float _dT)
{
	bird::Update(_dT);

	if (!m_bActivated && m_bHasLaunched)
	{
		m_fTimer += _dT;
		if (m_fTimer > 0.5f)
		{
			m_fTimer = 0.5f;
		}
		m_Sprite->setScale(m_StartScale * (1 + 2.0f * m_fTimer));
	}
	if (m_fTimer >= 0.5f && !m_bActivated && m_bHasLaunched)
	{
		m_bActivated = true;

		m_Body->DestroyFixture(m_Body->GetFixtureList()->GetNext());
		float radius = m_Sprite->getTexture()->getSize().x * m_Sprite->getScale().x / 2;

		b2CircleShape* newCircle = new b2CircleShape();
		newCircle->m_p.Set(0.0f, 0.0f);
		newCircle->m_radius = radius * Utilities::MPP;

		m_FixtureDef = new b2FixtureDef();
		m_FixtureDef->shape = newCircle;
		m_FixtureDef->density = 1.0f;
		m_FixtureDef->friction = 0.3f;
		m_FixtureDef->restitution = 0.9f;

		m_Body->CreateFixture(m_FixtureDef);
	}
}

