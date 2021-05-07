#ifndef __BIRD_SPIN_H__
#define __BIRD_SPIN_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   birdSpin.h
//  Description :   Class for Spinning bird object which will gain a burst of torque after a delay, allow the bird to roll backwards.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "bird.h"
 // Implementation 
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