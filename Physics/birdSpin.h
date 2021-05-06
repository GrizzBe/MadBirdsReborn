#ifndef __BIRD_SPIN_H__
#define __BIRD_SPIN_H__

#include "bird.h"

class birdSpin :
	public bird
{
public:
	birdSpin(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape);
	virtual ~birdSpin();
	virtual void Update(float _dT);
private:
	float m_SpinTimer;
};

#endif