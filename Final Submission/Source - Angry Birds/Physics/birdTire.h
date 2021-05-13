#ifndef __BIRD_TIRE_H__
#define __BIRD_TIRE_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   birdTire.h
//  Description :   Class for Tire bird object which will inflate after being launched making it heavier and bouncier.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "bird.h"
class birdTire :
    public bird
{
public:
    birdTire(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape);
    virtual ~birdTire();

    virtual void Update(float _dT);
private:
    float m_fTimer;
    sf::Vector2f m_StartScale;
};

#endif