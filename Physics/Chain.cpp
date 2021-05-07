// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   Chain.cpp
//  Description :   Box2D chain.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // This Include 
#include "Chain.h"
 // Implementation 
Chain::Chain(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, b2World* _world, bool _destructable)
{
    // Create chain base
    gameObject* chainBase = new gameObject(_pos, _scale, 0.0f, _texture, b2_staticBody, _world, 2, false);
    m_ChainLinks.push_back(chainBase);

    b2RevoluteJointDef jd;
    jd.collideConnected = false;

    b2Body* prevBody = chainBase->GetBody();

    for (int i = 1; i < 15; ++i) // Add chain link to chain vector.
    {
        gameObject* newChain = new gameObject(b2Vec2(_pos.x, _pos.y + i * 0.8f), _scale, 0.0f, _texture, b2_dynamicBody, _world, 2, false);
        m_ChainLinks.push_back(newChain);
        b2Body* body = newChain->GetBody();

        b2Vec2 anchor((body->GetPosition().x + prevBody->GetPosition().x) / 2, (body->GetPosition().y + prevBody->GetPosition().y) / 2);
        jd.Initialize(prevBody, body, anchor);
        _world->CreateJoint(&jd);

        prevBody = body;
    }
}

Chain::~Chain()
{
    std::vector<gameObject*>::iterator it = m_ChainLinks.begin();
    while (it != m_ChainLinks.end())
    {
        // Delete vector contents
        delete* it;
        it = m_ChainLinks.erase((it));
    }
}

/***********************
* Update: Update chain links.
* @author: William de Beer
* @parameter: Delta time
********************/
void Chain::Update(float _dT)
{
    for (auto i : m_ChainLinks)
    {
        i->Update(_dT);
    }
}

/***********************
* Draw: Draw chain links.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void Chain::Draw(sf::RenderWindow& _window)
{
    for (auto i : m_ChainLinks)
    {
        _window.draw(*i->GetSprite());
    }
}
