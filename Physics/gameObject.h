#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <SFML/Graphics.hpp>
#include <box2d.h>
#include "Utilities.h"

struct GameObjectData {
	float durability = 100.0f;
};

class gameObject
{
public:
	gameObject(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape, bool _destructable);
	virtual ~gameObject();

	virtual void Update(float _dT);
	bool IsDestructable();
	float GetDurability();
	void SetDurability(float _durability);
	sf::Sprite* GetSprite();
	b2Body* GetBody();
	bool GetMouseColliding(sf::RenderWindow& _window);
	bool GetLethal() { return m_bLethal; };
	void SetLethal(bool _bool) { m_bLethal = _bool; };

protected:
	bool m_bDestructable;
	bool m_bLethal;
	float m_MaxDurability;
	float m_Durability;
	b2Vec2 m_StoredVelocity;

	sf::Sprite* m_Sprite;
	b2Body* m_Body;
	b2BodyDef* m_BodyDef;

	b2FixtureDef* m_FixtureDef;
	b2World* m_World;
};

#endif