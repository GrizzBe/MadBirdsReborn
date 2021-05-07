// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   gameObject.cpp
//  Description :   Class for all box2D gameobjects including blocks and birds.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // This Include 
#include "gameObject.h"
 // Implementation 
gameObject::gameObject(b2Vec2 _pos, sf::Vector2f _scale, float _rotation, sf::Texture* _texture, b2BodyType _bodyType, b2World* _world, int _shape, bool _destructable)
{
	m_bLethal = false;
	m_FixtureDef = 0;
	// Set durability
	m_MaxDurability = 10.0f;
	m_Durability = m_MaxDurability;

	m_bDestructable = _destructable;
	m_StoredVelocity.x = 0;
	m_StoredVelocity.y= 0;

	// Create sprite
	m_Sprite = new sf::Sprite(*_texture);
	m_Sprite->setPosition(_pos.x * Utilities::PPM, _pos.y * Utilities::PPM);
	m_Sprite->setScale(_scale.x * 32.0f / _texture->getSize().x, _scale.y * 32.0f / _texture->getSize().y);
	m_Sprite->setOrigin(_texture->getSize().x / 2, _texture->getSize().y / 2);
	m_Sprite->setRotation(_rotation);
	
	// Create body
	m_BodyDef = new b2BodyDef();
	m_BodyDef->type = _bodyType;
	m_BodyDef->position.Set(_pos.x, _pos.y);
	m_BodyDef->angle = _rotation * 180.0f / b2_pi;

	m_BodyDef->userData.pointer = reinterpret_cast<uintptr_t>(this);

	m_Body = _world->CreateBody(m_BodyDef);
	// Create fixture def
	if (_shape == 1)
	{
		b2PolygonShape newBox;
		float width = 0.5f * _texture->getSize().x * m_Sprite->getScale().x;
		float height = 0.5f * _texture->getSize().y * m_Sprite->getScale().y;
		newBox.SetAsBox(width * Utilities::MPP, height * Utilities::MPP);
		
		m_FixtureDef = new b2FixtureDef();
		m_FixtureDef->shape = &newBox;
		m_FixtureDef->density = 1.0f;
		m_FixtureDef->friction = 0.7f;

		m_Body->CreateFixture(m_FixtureDef);
	}
	else if (_shape == 2)
	{
		float radius = _texture->getSize().x * m_Sprite->getScale().x / 2;

		b2CircleShape newCircle;
		newCircle.m_p.Set(0.0f, 0.0f);
		newCircle.m_radius = radius * Utilities::MPP;

		m_FixtureDef = new b2FixtureDef();
		m_FixtureDef->shape = &newCircle;
		m_FixtureDef->density = 1.0f;
		m_FixtureDef->friction = 0.3f;
		m_FixtureDef->restitution = 0.05f;

		m_Body->CreateFixture(m_FixtureDef);
	}
	// Save world
	m_World = _world;
}

gameObject::~gameObject()
{
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = 0;
	}
	if (m_Body != nullptr)
	{
		m_World->DestroyBody(m_Body);
		m_Body = 0;
	}
	if (m_BodyDef != nullptr)
	{
		delete m_BodyDef;
		m_BodyDef = 0;
	}
	if (m_FixtureDef != nullptr)
	{
		delete m_FixtureDef;
		m_FixtureDef = 0;
	}
}

/***********************
* Update: Updates sprite positions.
* @author: William de Beer
* @parameter: Delta time
********************/
void gameObject::Update(float _dT)
{
	b2Vec2 pos = m_Body->GetPosition();
	float rot = m_Body->GetAngle() * 180.0f / b2_pi;
	m_Sprite->setPosition(pos.x * Utilities::PPM, pos.y * Utilities::PPM);
	m_Sprite->setRotation(rot);
}

/***********************
* IsDestructable: Returns whether object is destructable.
* @author: William de Beer
* @return: Boolean
********************/
bool gameObject::IsDestructable()
{
	return m_bDestructable;
}

/***********************
* GetDurability: Returns remaining durability of object.
* @author: William de Beer
* @return: Durability float.
********************/
float gameObject::GetDurability()
{
	return m_Durability;
}

/***********************
* SetDurability: Sets the durability of object.
* @author: William de Beer
* @parameter: Float durability
********************/
void gameObject::SetDurability(float _durability)
{
	m_Durability = _durability;
}

/***********************
* GetSprite: Returns object sprite.
* @author: William de Beer
* @return: Pointer to sprite
********************/
sf::Sprite* gameObject::GetSprite()
{
	return m_Sprite;
}

/***********************
* GetBody: Returns object body.
* @author: William de Beer
* @return: Pointer to body
********************/
b2Body* gameObject::GetBody()
{
	return m_Body;
}

/***********************
* GetMouseColliding: Checks if mouse is in radius.
* @author: William de Beer
* @parameter: Reference to render window
* @return: Boolean
********************/
bool gameObject::GetMouseColliding(sf::RenderWindow& _window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
	sf::Vector2f distanceVector = (sf::Vector2f)mousePos - m_Sprite->getPosition();
	float distance = sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));

	if (distance < 20.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}
