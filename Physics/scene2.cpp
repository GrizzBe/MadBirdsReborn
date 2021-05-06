#include "scene2.h"

scene2::scene2()
{
    m_Chain1 = 0;
}

scene2::~scene2()
{
}

void scene2::Update(float _dT)
{
    gameWorld::Update(_dT);
    if (m_Chain1 != nullptr)
        m_Chain1->Update(_dT);
    if (m_Prismatic != nullptr)
        m_Prismatic->Update(_dT);
}

void scene2::Render(sf::RenderWindow& _window)
{
    _window.clear(sf::Color(228, 228, 228));

    if (m_Prismatic != nullptr)
        m_Prismatic->Draw(_window);
    gameWorld::Render(_window);
    if (m_Chain1 != nullptr)
        m_Chain1->Draw(_window);

    _window.display();
}

void scene2::GenerateLevel(b2World& _world)
{
    AddBird(birdType::tireBird, _world);
    AddBird(birdType::tireBird, _world);
    AddBird(birdType::basicBird, _world);
    AddBird(birdType::basicBird, _world);

    gameWorld::GenerateLevel(_world);

    float xBuildingOffset = 22.0f;
    float yBuildingOffset = 14.0f;

    m_Prismatic = new prismatic(b2Vec2(-6.0f + xBuildingOffset, 8.0f + yBuildingOffset), sf::Vector2f(2.0f, 2.0f), m_WeightTexture, m_RailTexture, &_world, false);
    // Wall 1
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 6.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 7.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 8.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 9.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

    // Wall2
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 6.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 7.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 8.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 9.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    
    // Ceiling 1
    m_Blocks.push_back(new gameObject(b2Vec2(3.5f + xBuildingOffset, 5.0f + yBuildingOffset), sf::Vector2f(8.0f, 1.0f), 0.0f, m_StrongBlockTexture, b2_dynamicBody, &_world, 1, false));

    // Wall 3
    m_Blocks.push_back(new gameObject(b2Vec2(1.0f + xBuildingOffset, 1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(1.0f + xBuildingOffset, 2.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(1.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(1.0f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    
    // Wall 4
    m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 2.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

    // Ceiling 2
    m_Blocks.push_back(new gameObject(b2Vec2(3.5f + xBuildingOffset, 0.0f + yBuildingOffset), sf::Vector2f(6.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

    // Concrete block 1
    m_Blocks.push_back(new gameObject(b2Vec2(11.0f + xBuildingOffset, 8.0f + yBuildingOffset), sf::Vector2f(3.0f, 5.0f), 0.0f, m_StrongBlockTexture, b2_dynamicBody, &_world, 1, false));
    // Ceiling 3
    m_Blocks.push_back(new gameObject(b2Vec2(9.5f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(6.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

    // Wall 5
    m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 2.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    // Wall 6 
    m_Blocks.push_back(new gameObject(b2Vec2(12.0f + xBuildingOffset, 1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(12.0f + xBuildingOffset, 2.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    m_Blocks.push_back(new gameObject(b2Vec2(12.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

    m_Blocks.push_back(new gameObject(b2Vec2(10.0f + xBuildingOffset, 0.0f + yBuildingOffset), sf::Vector2f(5.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
    
    m_Victims.push_back(new victim(b2Vec2(3.5f + xBuildingOffset, 7.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
    m_Victims.push_back(new victim(b2Vec2(3.5f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
    m_Victims.push_back(new victim(b2Vec2(10.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
    m_Victims.push_back(new victim(b2Vec2(7.0f + xBuildingOffset, -1.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
}

void scene2::DestroyBox2DObjects()
{
    if (m_Chain1 != nullptr)
    {
        delete m_Chain1;
        m_Chain1 = 0;
    }
    if (m_Prismatic != nullptr)
    {
        delete m_Prismatic;
        m_Prismatic = 0;
    }
    gameWorld::DestroyBox2DObjects();
}
