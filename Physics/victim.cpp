#include "victim.h"

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

void victim::Update(float _dT)
{
	if (m_Durability < m_MaxDurability)
	{
		m_Sprite->setTexture(*m_texDamaged);
	}

	gameObject::Update(_dT);
}
