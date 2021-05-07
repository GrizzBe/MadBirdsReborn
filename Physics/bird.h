#ifndef __BIRD_H__
#define __BIRD_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   bird.h
//  Description :   Class for basic bird object and parent to other types of bird objects.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "gameObject.h"
 // Implementation 
class bird : public gameObject
{
public:
	bird(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape);
	virtual ~bird();
	
	virtual void Update(float _dT);

	virtual bool GetIsSelected() { return m_bIsSelected; };
	virtual void SetIsSeleceted(bool _selected) { m_bIsSelected = _selected; };

	virtual bool GetHasLaunched() { return m_bHasLaunched; };
	virtual void SetHasLaunched(bool _launched) { m_bHasLaunched = _launched; };
protected:
	bool m_bIsSelected;
	bool m_bHasLaunched;
	bool m_bActivated;
};

#endif