#include "bird.h"

bird::bird(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape)
	: gameObject(_pos, _scale, _rotation, _texture, _bodyType, _world, _shape, false)
{
	m_bActivated = false;
	m_bIsSelected = false;
	m_bHasLaunched = false;
}

bird::~bird()
{
}

void bird::Update(float _dT)
{
	if (!m_bHasLaunched)
	{
		m_Durability = m_MaxDurability;
	}

	gameObject::Update(_dT);
}

