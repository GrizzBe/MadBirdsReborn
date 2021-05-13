#ifndef __SCENE2_H__
#define __SCENE2_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   scene2.h
//  Description :   Contains placement and updates of scene 2 objects.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "gameWorld.h"
 // Implementation 
class scene2 :
    public gameWorld
{
public:
    scene2() {};
    virtual ~scene2() {};

    /***********************
    * GenerateLevel: Places scene objects and birds.
    * @author: William de Beer
    * @parameter: Reference to world.
    ********************/
    virtual void GenerateLevel(b2World& _world)
    {
        // Add birds in
        AddBird(birdType::basicBird, _world);
        AddBird(birdType::tireBird, _world);
        AddBird(birdType::tireBird, _world);
        AddBird(birdType::tireBird, _world);

        gameWorld::GenerateLevel(_world);

        float xBuildingOffset = 22.0f;
        float yBuildingOffset = 14.0f;

        // Initialise prismatic
        m_Prismatic1 = new prismatic(b2Vec2(-6.0f + xBuildingOffset, 8.0f + yBuildingOffset), sf::Vector2f(2.0f, 2.0f), m_WeightTexture, m_RailTexture, &_world, false);
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
};

#endif