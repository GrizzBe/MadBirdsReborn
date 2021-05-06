#pragma once
#include "gameObject.h"
class victim :
    public gameObject
{
public:
	victim(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, sf::Texture* _damagedTexture, b2BodyType _bodyType, b2World* _world, int _shape);
	virtual ~victim();

	virtual void Update(float _dT);
private:
	sf::Texture* m_texDamaged;
};

