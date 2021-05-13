#ifndef __BIRD_QUE_H__
#define __BIRD_QUE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   birdQue.h
//  Description :   Class for Quebird object which will gain a burst of speed in a direction after a second. Quebird == Cube bird... get it lol?
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "bird.h"
 // Implementation 
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
