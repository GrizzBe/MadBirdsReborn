#ifndef __BIRD_QUE_H__
#define __BIRD_QUE_H__
#include "bird.h"
class birdQue :
    public bird
{
public:
	birdQue(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, sf::Texture* _texture2, b2BodyType _bodyType, b2World* _world, int _shape);
	virtual ~birdQue();
	virtual void Update(float _dT);
private:
	float m_fDropTimer;
	sf::Texture* m_Texture2;
};
#endif
