#ifndef __SCENE1_H__
#define __SCENE1_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   scene1.h
//  Description :   Contains placement and updates of scene 1 objects.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Local Includes 
#include "gameWorld.h"
 // Implementation 
class scene1 :
    public gameWorld
{
public:
    scene1() {};
    virtual ~scene1() {};

    /***********************
    * GenerateLevel: Places scene objects and birds.
    * @author: William de Beer
    * @parameter: Reference to world.
    ********************/
    virtual void GenerateLevel(b2World& _world)
    {
        // Add birds in
        AddBird(birdType::queBird, _world);
        AddBird(birdType::basicBird, _world);
        AddBird(birdType::spinBird, _world);
        AddBird(birdType::spinBird, _world);

        gameWorld::GenerateLevel(_world);

        // Initialise chain
        m_Chain1 = new Chain(b2Vec2(29.5f, 1.5f), sf::Vector2f(1.0f, 1.0f), m_ChainTexture, &_world, false);

        float xBuildingOffset = 26.0f;
        float yBuildingOffset = 18.0f;
        // Initialise seesaw
        m_Seesaw1 = new seesaw(b2Vec2(-4.0f + xBuildingOffset, 2.5f + yBuildingOffset), sf::Vector2f(10.0f, 1.0f), m_SeesawTexture, m_ChainTexture, &_world, false);

        // Wall 1
        m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, -1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_StrongBlockTexture, b2_dynamicBody, &_world, 1, false));
        m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        //m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 2.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        m_Blocks.push_back(new gameObject(b2Vec2(0.0f + xBuildingOffset, 5.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

        // Wall 2
        m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, -1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_StrongBlockTexture, b2_dynamicBody, &_world, 1, false));
        m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 1.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 2.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 3.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));
        m_Blocks.push_back(new gameObject(b2Vec2(7.0f + xBuildingOffset, 5.0f + yBuildingOffset), sf::Vector2f(1.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

        // Ceiling 1
        m_Blocks.push_back(new gameObject(b2Vec2(3.5f + xBuildingOffset, 0.0f + yBuildingOffset), sf::Vector2f(8.0f, 1.0f), 0.0f, m_WeakBlockTexture, b2_dynamicBody, &_world, 1, true));

        // Enemies
        m_Victims.push_back(new victim(b2Vec2(3.5f + xBuildingOffset, 4.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
        m_Victims.push_back(new victim(b2Vec2(3.5f + xBuildingOffset, -1.0f + yBuildingOffset), sf::Vector2f(1.5f, 1.5), 0.0f, m_VictimTexture, m_VictimTexture2, b2_dynamicBody, &_world, 2));
    }
};

#endif