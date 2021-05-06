#ifndef __SEESAW_H__
#define __SEESAW_H__
#include "gameObject.h"

class seesaw
{
public:

	seesaw(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, sf::Texture* _pivotTexture, b2World* _world, bool _destructable);
	~seesaw();

	void Update(float _dT);
	void Draw(sf::RenderWindow& _window);
private:
	b2RevoluteJoint* m_Joint;
	gameObject* m_Object;
	gameObject* m_Ground;
};

#endif