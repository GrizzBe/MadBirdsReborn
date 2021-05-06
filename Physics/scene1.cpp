#include "scene1.h"

scene1::scene1()
{
    m_Chain1 = nullptr;
}

scene1::~scene1()
{
}

void scene1::Update(float _dT)
{
    gameWorld::Update(_dT);
    if (m_Chain1 != nullptr)
        m_Chain1->Update(_dT);
    if (m_Seesaw1 != nullptr)
        m_Seesaw1->Update(_dT);
}

void scene1::Render(sf::RenderWindow& _window)
{
    _window.clear(sf::Color(228, 228, 228));

    if (m_Seesaw1 != nullptr)
        m_Seesaw1->Draw(_window);
    gameWorld::Render(_window);
    if (m_Chain1 != nullptr)
        m_Chain1->Draw(_window);
    _window.display();
}

void scene1::GenerateLevel(b2World& _world)
{
    AddBird(birdType::queBird, _world);
    AddBird(birdType::basicBird, _world);
    AddBird(birdType::spinBird, _world);
    AddBird(birdType::spinBird, _world);

    gameWorld::GenerateLevel(_world);

    m_Chain1 = new Chain(b2Vec2(29.5f, 1.5f), sf::Vector2f(1.0f, 1.0f), m_ChainTexture, &_world, false);

    float xBuildingOffset = 26.0f;
    float yBuildingOffset = 18.0f;
    m_Seesaw1 = new seesaw(b2Vec2(-4.0f + xBuildingOffset, 2.5f + yBuildingOffset), sf::Vector2f(10.0f, 1.0f), m_SeesawTexture, m_ChainTexture, &_world, false);

    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, -1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    //m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 2.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 5.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, -1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 2.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 5.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

    m_Blocks.push_back(new gameObject(b2Vec2(3.5f + xBuildingOffset, 0.0f + yBuildingOffset), sf::Vector2f(8.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

    m_Victims.push_back(new victim(b2Vec2(3.5f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
    m_Victims.push_back(new victim(b2Vec2(3.5f + xBuildingOffset, -1.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
}

void scene1::DestroyBox2DObjects()
{
    if (m_Chain1 != nullptr)
    {
        delete m_Chain1;
        m_Chain1 = 0;
    }
    gameWorld::DestroyBox2DObjects();
}


