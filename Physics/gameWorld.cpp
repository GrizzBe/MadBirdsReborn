// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   gameWorld.cpp
//  Description :   Parent to all game scenes.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // Local Includes 
#include "gameObject.h"
 // This Include 
#include "gameWorld.h"
 // Implementation 
gameWorld::gameWorld()
{
    m_contactList = 0;
    m_bPullFlag = false;
    m_DragOrigin = { 0,0 };
    m_fForceMult = 10.0f;
    m_fForceMax = 1000.0f;
    m_SelectedBird = 0;

    m_BirdTexture = 0;
    m_BirdTireTexture = 0;
    m_BirdSpinTexture = 0;
    m_BirdQueTexture = 0;
    m_BirdQueTexture2 = 0;

    m_VictimTexture = 0;
    m_VictimTexture2 = 0;

    m_StrongBlockTexture = 0;
    m_WeakBlockTexture = 0;

    m_SeesawTexture = 0;
    m_ChainTexture = 0;
    m_RailTexture = 0;
    m_WeightTexture = 0;

    m_ArrowTexture = 0;
    m_AimingArrow = 0;

    m_Chain1 = 0;
    m_Seesaw1 = 0;
    m_Prismatic1 = 0;
}

gameWorld::~gameWorld()
{
    // Delete all textures and sprites
    if (m_BirdTexture != nullptr)
    {
        delete m_BirdTexture;
        m_BirdTexture = 0;
    }
    if (m_BirdTireTexture != nullptr)
    {
        delete m_BirdTireTexture;
        m_BirdTireTexture = 0;
    }
    if (m_BirdSpinTexture != nullptr)
    {
        delete m_BirdSpinTexture;
        m_BirdSpinTexture = 0;
    }
    if (m_BirdQueTexture != nullptr)
    {
        delete m_BirdQueTexture;
        m_BirdQueTexture = 0;
    }
    if (m_BirdQueTexture2 != nullptr)
    {
        delete m_BirdQueTexture2;
        m_BirdQueTexture2 = 0;
    }
    if (m_VictimTexture != nullptr)
    {
        delete m_VictimTexture;
        m_VictimTexture = 0;
    }
    if (m_VictimTexture2 != nullptr)
    {
        delete m_VictimTexture2;
        m_VictimTexture2 = 0;
    }
    if (m_StrongBlockTexture != nullptr)
    {
        delete m_StrongBlockTexture;
        m_StrongBlockTexture = 0;
    }
    if (m_WeakBlockTexture != nullptr)
    {
        delete m_WeakBlockTexture;
        m_WeakBlockTexture = 0;
    }
    if (m_ChainTexture != nullptr)
    {
        delete m_ChainTexture;
        m_ChainTexture = 0;
    }
    if (m_SeesawTexture != nullptr)
    {
        delete m_SeesawTexture;
        m_SeesawTexture = 0;
    }
    if (m_WeightTexture != nullptr)
    {
        delete m_WeightTexture;
        m_WeightTexture = 0;
    }
    if (m_RailTexture != nullptr)
    {
        delete m_RailTexture;
        m_RailTexture = 0;
    }
    if (m_ArrowTexture != nullptr)
    {
        delete m_ArrowTexture;
        m_ArrowTexture = 0;
    }
    if (m_AimingArrow != nullptr)
    {
        delete m_AimingArrow;
        m_AimingArrow = 0;
    }
}

/***********************
* MainLoop: Main loop which calls render and update functions.
* @author: William de Beer
* @parameter: Reference to render window
********************/
void gameWorld::MainLoop(sf::RenderWindow& _window) // Warning is a non-issue.
{
    float timeStep = 1.0f / 60.0f;
    int32 velIter = 6;
    int32 posIter = 2;

    LoadTextures();
    b2World m_World(b2Vec2(0.0f, 9.81f));

    // Set contact listener
    m_contactList = new ContactListener();
    m_World.SetContactListener(m_contactList);

    m_AimingArrow = new sf::Sprite(*m_ArrowTexture);

    // Generate level
    GenerateLevel(m_World);
    
    sf::Clock clock;
    float LevelEndTimer = 0;
    while (_window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        // Delta time update
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        LaunchBird(_window);
        m_World.Step(timeStep, velIter, posIter);
        Update(deltaTime);
        Render(_window);
    }
    DestroyBox2DObjects();
}

/***********************
* Update: Call updates for all game objects in world.
* @author: William de Beer
* @parameter: Delta time
********************/
void gameWorld::Update(float _dT)
{
    // Update blocks
    std::vector<gameObject*>::iterator bl_it = m_Blocks.begin();
    while (bl_it != m_Blocks.end())
    {
        (*bl_it)->Update(_dT);

        if ((*bl_it)->GetDurability() <= 0.0f && (*bl_it)->IsDestructable()) // Check if block is to be destroyed.
        {
            // Delete vector contents
            delete* bl_it;
            bl_it = m_Blocks.erase((bl_it));
        }
        else
        {
            bl_it++;
        }
    }

    // Update victims
    std::vector<victim*>::iterator v_it = m_Victims.begin();
    while (v_it != m_Victims.end())
    {
        (*v_it)->Update(_dT);

        if ((*v_it)->GetDurability() <= 0.0f && (*v_it)->IsDestructable()) // Check if block is to be destroyed.
        {
            // Delete vector contents
            delete* v_it;
            v_it = m_Victims.erase((v_it));
        }
        else
        {
            v_it++;
        }
    }

    // Update birds
    for (auto i : m_Birds)
    {
        i->Update(_dT);
    }

    // Update joint objects
    if (m_Seesaw1 != nullptr)
        m_Seesaw1->Update(_dT);

    if (m_Chain1 != nullptr)
        m_Chain1->Update(_dT);

    if (m_Prismatic1 != nullptr)
        m_Prismatic1->Update(_dT);
}

/***********************
* Render: Render all game objects in world.
* @author: William de Beer
* @parameter: Reference to render window
********************/
void gameWorld::Render(sf::RenderWindow& _window)
{
    _window.clear(sf::Color(228, 228, 228));

    // Draw joints
    if (m_Seesaw1 != nullptr)
        m_Seesaw1->Draw(_window);

    if (m_Chain1 != nullptr)
        m_Chain1->Draw(_window);

    if (m_Prismatic1 != nullptr)
        m_Prismatic1->Draw(_window);

    // Draw blocks
    for (auto i : m_Blocks)
    {
        _window.draw(*i->GetSprite());
    }
    // Draw birds
    for (auto i : m_Birds)
    {
        // Draw outline around selected bird.
        if (i == m_SelectedBird)
        {
            sf::CircleShape selectedOutline;
            float radius = 18.0f;
            selectedOutline.setFillColor(sf::Color::Green);
            selectedOutline.setRadius(radius);
            selectedOutline.setOrigin(sf::Vector2f(radius, radius));
            selectedOutline.setPosition(i->GetSprite()->getPosition());
            _window.draw(selectedOutline);
        }
        _window.draw(*i->GetSprite());
    }
    // Draw victims
    for (auto i : m_Victims)
    {
        _window.draw(*i->GetSprite());
    }
    // Draw aiming arrow
    if (m_bPullFlag)
    {
        _window.draw(*m_AimingArrow);
    }
    _window.display();
}

/***********************
* LoadTextures: Loads all texture use in world from files.
* @author: William de Beer
********************/
void gameWorld::LoadTextures()
{
    m_BirdTexture = new sf::Texture();
    if (!m_BirdTexture->loadFromFile("Assets/Bird.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_BirdTireTexture = new sf::Texture();
    if (!m_BirdTireTexture->loadFromFile("Assets/BirdTire.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_BirdSpinTexture = new sf::Texture();
    if (!m_BirdSpinTexture->loadFromFile("Assets/BirdSpin.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_BirdQueTexture = new sf::Texture();
    if (!m_BirdQueTexture->loadFromFile("Assets/BirdQue.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_BirdQueTexture2 = new sf::Texture();
    if (!m_BirdQueTexture2->loadFromFile("Assets/BirdQue2.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_VictimTexture = new sf::Texture();
    if (!m_VictimTexture->loadFromFile("Assets/Victim.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_VictimTexture2 = new sf::Texture();
    if (!m_VictimTexture2->loadFromFile("Assets/VictimDamaged.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_StrongBlockTexture = new sf::Texture();
    if (!m_StrongBlockTexture->loadFromFile("Assets/StrongBlock.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_WeakBlockTexture = new sf::Texture();
    if (!m_WeakBlockTexture->loadFromFile("Assets/WeakBlock.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_SeesawTexture = new sf::Texture();
    if (!m_SeesawTexture->loadFromFile("Assets/Seesaw.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_ChainTexture = new sf::Texture();
    if (!m_ChainTexture->loadFromFile("Assets/ChainLink.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_WeightTexture = new sf::Texture();
    if (!m_WeightTexture->loadFromFile("Assets/PrismaticWeight.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_RailTexture = new sf::Texture();
    if (!m_RailTexture->loadFromFile("Assets/PrismaticRail.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }

    m_ArrowTexture = new sf::Texture();
    if (!m_ArrowTexture->loadFromFile("Assets/Arrow.png"))
    {
        std::cout << "Texture not loaded" << std::endl;
    }
}

/***********************
* AddBird: Adds bird into scene.
* @author: William de Beer
* @parameter: Bird type, reference to world.
********************/
void gameWorld::AddBird(birdType _type, b2World& _world)
{
    // Offset constant
    float xBirdOffset = 1.75f;
    float yBirdOffset = 17.5f;

    // Set spawn position based on how many birds are already in scene
    b2Vec2 spawnPos(xBirdOffset + m_Birds.size() * 1.5f, yBirdOffset);

    // Spawn bird
    switch (_type)
    {
    case birdType::basicBird:
        m_Birds.push_back(new bird(spawnPos, sf::Vector2f(1.0f, 1.0f), 0.0f, m_BirdTexture, b2_dynamicBody, &_world, 2));
        break;
    case birdType::tireBird:
        m_Birds.push_back(new birdTire(spawnPos, sf::Vector2f(1.0f, 1.0f), 0.0f, m_BirdTireTexture, b2_dynamicBody, &_world, 2));
        break;
    case birdType::spinBird:
        m_Birds.push_back(new birdSpin(spawnPos, sf::Vector2f(1.0f, 1.0f), 0.0f, m_BirdSpinTexture, b2_dynamicBody, &_world, 2));
        break;
    case birdType::queBird:
        m_Birds.push_back(new birdQue(spawnPos, sf::Vector2f(1.0f, 1.0f), 0.0f, m_BirdQueTexture, m_BirdQueTexture2, b2_dynamicBody, &_world, 2));
        break;
    default:
        std::cout << "That's not a bird! That's a bug!" << std::endl;
        break;
    }
}

/***********************
* DestroyBox2DObjects: Destroys all box2D objects, called before deconstructor.
* @author: William de Beer
********************/
void gameWorld::DestroyBox2DObjects()
{
    if (m_Chain1 != nullptr)
    {
        delete m_Chain1;
        m_Chain1 = 0;
    }
    if (m_Seesaw1 != nullptr)
    {
        delete m_Seesaw1;
        m_Seesaw1 = 0;
    }
    if (m_Prismatic1 != nullptr)
    {
        delete m_Prismatic1;
        m_Prismatic1 = 0;
    }

    std::vector<bird*>::iterator b_it = m_Birds.begin();
    while (b_it != m_Birds.end())
    {
        // Delete vector contents
        delete* b_it;
        b_it = m_Birds.erase((b_it));
    }
    m_Birds.clear();

    std::vector<victim*>::iterator v_it = m_Victims.begin();
    while (v_it != m_Victims.end())
    {
        // Delete vector contents
        delete* v_it;
        v_it = m_Victims.erase((v_it));
    }
    m_Victims.clear();

    std::vector<gameObject*>::iterator bl_it = m_Blocks.begin();
    while (bl_it != m_Blocks.end())
    {
        // Delete vector contents
        delete* bl_it;
        bl_it = m_Blocks.erase((bl_it));
    }
    m_Blocks.clear();

    if (m_contactList != nullptr)
    {
        delete m_contactList;
        m_contactList = 0;
    }
}

/***********************
* LaunchBird: Logic for launching bird.
* @author: William de Beer
* @parameter: Reference to render window.
********************/
void gameWorld::LaunchBird(sf::RenderWindow& _window)
{
    if (m_SelectedBird != nullptr) // Check if bird is selected
    {
        // Check if mouse is colliding with bird.
        bool mouseColliding = m_SelectedBird->GetMouseColliding(_window);

        // Start power selection
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_bPullFlag && mouseColliding)
        {
            m_SelectedBird->SetHasLaunched(false);
            m_bPullFlag = true;
        }
        // Update arrow
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_bPullFlag)
        {
            m_DragOrigin = (sf::Vector2i)m_SelectedBird->GetSprite()->getPosition();
            m_AimingArrow->setPosition((sf::Vector2f)m_DragOrigin);
            b2Vec2 force = CalculateForce(_window);
            float angle = atan(force.y / force.x) * 180.0f / 3.14f;
            if (force.x < 0)
            {
                m_AimingArrow->setRotation(angle + 90.0f);
            }
            else
            {
                m_AimingArrow->setRotation(angle - 90.0f);
            }

            float length = sqrtf(powf(force.x, 2) + powf(force.y, 2));

            m_AimingArrow->setScale(1.0f, length / m_fForceMax);

            m_AimingArrow->setOrigin(0.5f * m_AimingArrow->getTexture()->getSize().x, 
                m_AimingArrow->getTexture()->getSize().y * m_AimingArrow->getScale().y + 10.0f);
        }

        // Hover highlight
		if (mouseColliding || m_bPullFlag)
		{
			m_SelectedBird->GetSprite()->setColor(sf::Color(128, 128, 128));
		}
		else
		{
			m_SelectedBird->GetSprite()->setColor(sf::Color(255, 255, 255));
		}

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_bPullFlag)
        {
            // Launch bird
            m_SelectedBird->SetHasLaunched(true);
            m_SelectedBird->GetBody()->ApplyForceToCenter(-CalculateForce(_window), true);
            m_bPullFlag = false;
			m_SelectedBird->GetSprite()->setColor(sf::Color(255, 255, 255));

            // Go next bird
			m_it++;
			if (m_it != m_Birds.end())
				m_SelectedBird = *m_it;
			else
				m_SelectedBird = nullptr;
        }
    }
}

/***********************
* CalculateForce: Description.
* @author: William de Beer
* @parameter: Reference to render window
* @return: 2D vector
********************/
b2Vec2 gameWorld::CalculateForce(sf::RenderWindow& _window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);
    sf::Vector2i positionDifference = sf::Mouse::getPosition(_window) - m_DragOrigin; // Get direction and difference of positions 

    // Create force vector from position difference
    b2Vec2 forceVec(positionDifference.x * m_fForceMult, positionDifference.y * m_fForceMult);
    float forceMag = sqrtf(powf(forceVec.x, 2) + powf(forceVec.y, 2));

    if (forceMag > m_fForceMax) // Clamp
    {
        forceVec.x = (forceVec.x * m_fForceMax) / forceMag;
        forceVec.y = (forceVec.y * m_fForceMax) / forceMag;
    }

    return forceVec;
}

/***********************
* GenerateLevel: Places scene objects and birds.
* @author: William de Beer
* @parameter: Reference to world.
********************/
void gameWorld::GenerateLevel(b2World& _world)
{
    // Check if a bird exists
    if (!m_Birds.empty())
    {
        // Select first bird
        m_it = m_Birds.begin();
        m_SelectedBird = *m_it;
    }
    else
    {
        std::cout << "No birds in scene" << std::endl;
    }

    // Create scene bounds
    m_Blocks.push_back(new gameObject(b2Vec2(20.0f, 25.0f), sf::Vector2f(40.0f, 2.0f), 0.0f, m_StrongBlockTexture, b2_staticBody, &_world, 1, false));
    m_Blocks.push_back(new gameObject(b2Vec2(0.0f, 13.2f), sf::Vector2f(2.0f, 40.0f), 0.0f, m_StrongBlockTexture, b2_staticBody, &_world, 1, false));
    m_Blocks.push_back(new gameObject(b2Vec2(37.5f, 13.2f), sf::Vector2f(2.0f, 40.0f), 0.0f, m_StrongBlockTexture, b2_staticBody, &_world, 1, false));
    m_Blocks.push_back(new gameObject(b2Vec2(20.0f, 0.0f), sf::Vector2f(40.0f, 2.0f), 0.0f, m_StrongBlockTexture, b2_staticBody, &_world, 1, false));

    float xStepsOffset = 1.0f;

    int birdCount = m_Birds.size();
    float yStepsOffset = 23.5f - birdCount;

    // Create stairs for birds.
    for (int i = 1; i < birdCount + 1; i++)
    {
        m_Blocks.push_back(new gameObject(b2Vec2(xStepsOffset + 0.75f * i, yStepsOffset + i), sf::Vector2f(i * 1.5f, 1.0f), 0.0f, m_WeakBlockTexture, b2_staticBody, &_world, 1, false));
    }
}
