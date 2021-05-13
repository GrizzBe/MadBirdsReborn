#ifndef __SCENE3_H__
#define __SCENE3_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   scene3.h
//  Description :   Contains placement and updates of scene 3 objects.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "gameWorld.h"
 // Implementation 
class scene3 :
    public gameWorld
{
public:
    scene3() {};
    virtual ~scene3() {};

    /***********************
    * GenerateLevel: Places scene objects and birds.
    * @author: William de Beer
    * @parameter: Reference to world.
    ********************/
    virtual void GenerateLevel(b2World& _world)
    {
        // Add birds in
        AddBird(birdType::spinBird, _world);
        AddBird(birdType::tireBird, _world);
        AddBird(birdType::tireBird, _world);
        AddBird(birdType::queBird, _world);

        gameWorld::GenerateLevel(_world);

        float xBuildingOffset = 17.0f;
        float yBuildingOffset = 4.5f;

        m_Distance1 = new distance(b2Vec2(9.0f + xBuildingOffset, yBuildingOffset + 9.0f), sf::Vector2f(2.0f, 2.0f), m_WeightTexture, m_RailTexture, m_PivotTexture, &_world);

        // Layer 1
        {
            // Wall 1
            m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 16.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 17.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 18.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 19.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

            // Wall 2
            m_Blocks.push_back(new gameObject(b2Vec2(4.0f + xBuildingOffset, 16.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(4.0f + xBuildingOffset, 17.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(4.0f + xBuildingOffset, 18.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(4.0f + xBuildingOffset, 19.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

            // Wall 3
            m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 16.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 17.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 18.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 19.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

            // Wall 4
            m_Blocks.push_back(new gameObject(b2Vec2(12.0f + xBuildingOffset, 16.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(12.0f + xBuildingOffset, 17.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(12.0f + xBuildingOffset, 18.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(12.0f + xBuildingOffset, 19.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

            // Ceiling 1
            m_Blocks.push_back(new gameObject(b2Vec2(6.f + xBuildingOffset, 15.0f + yBuildingOffset), sf::Vector2f(13.0f, 1.0f), 0.0f, m_StrongBlockTexture, b2_dynamicBody, &_world, 1, false));

            // Victims
            m_Victims.push_back(new victim(b2Vec2(2.0f + xBuildingOffset, 18.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
            m_Victims.push_back(new victim(b2Vec2(6.0f + xBuildingOffset, 18.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
            m_Victims.push_back(new victim(b2Vec2(10.0f + xBuildingOffset, 18.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
        }

        // Layer 2
        {
            // Wall 1
            m_Blocks.push_back(new gameObject(b2Vec2(2.0f + xBuildingOffset, 11.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(2.0f + xBuildingOffset, 12.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(2.0f + xBuildingOffset, 13.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(2.0f + xBuildingOffset, 14.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

            // Wall 2
            m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 11.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 12.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 13.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 14.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

            // Wall 3
            m_Blocks.push_back(new gameObject(b2Vec2(10.0f + xBuildingOffset, 11.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(10.0f + xBuildingOffset, 12.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(10.0f + xBuildingOffset, 13.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
            m_Blocks.push_back(new gameObject(b2Vec2(10.0f + xBuildingOffset, 14.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

            // Ceiling 1
            m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 10.0f + yBuildingOffset), sf::Vector2f(9.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

            // Victims
            m_Victims.push_back(new victim(b2Vec2(4.0f + xBuildingOffset, 13.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
            m_Victims.push_back(new victim(b2Vec2(8.0f + xBuildingOffset, 13.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
        }


        //// Layer 3
        //{
        //    // Wall 1
        //    m_Blocks.push_back(new gameObject(b2Vec2(4.0f + xBuildingOffset, 6.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //    m_Blocks.push_back(new gameObject(b2Vec2(4.0f + xBuildingOffset, 7.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //    m_Blocks.push_back(new gameObject(b2Vec2(4.0f + xBuildingOffset, 8.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //    m_Blocks.push_back(new gameObject(b2Vec2(4.0f + xBuildingOffset, 9.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //    // Wall 2
        //    m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 6.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //    m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 7.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //    m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 8.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //    m_Blocks.push_back(new gameObject(b2Vec2(8.0f + xBuildingOffset, 9.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //    // Ceiling 1
        //    m_Blocks.push_back(new gameObject(b2Vec2(6.0f + xBuildingOffset, 5.0f + yBuildingOffset), sf::Vector2f(5.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //}
        //Enemies

    }
};

#endif