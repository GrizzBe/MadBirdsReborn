#include "Chain.h"
#include <iostream>
Chain::Chain(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, b2World* _world, bool _destructable)
{
    gameObject* chainBase = new gameObject(_pos, _scale, 0.0f, _texture, b2_staticBody, _world, 2, false);
    m_ChainLinks.push_back(chainBase);

    b2RevoluteJointDef jd;
    jd.collideConnected = false;

    b2Body* prevBody = chainBase->GetBody();

    for (int i = 1; i < 15; ++i)
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

void Chain::Update(float _dT)
{
    for (auto i : m_ChainLinks)
    {
        i->Update(_dT);
    }
}

void Chain::Draw(sf::RenderWindow& _window)
{
    for (auto i : m_ChainLinks)
    {
        _window.draw(*i->GetSprite());
    }
}
