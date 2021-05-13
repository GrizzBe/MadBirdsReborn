// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   ContactListener.cpp
//  Description :   Registers contacts between box2D objects.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <iostream>
 // This Include 
#include "ContactListener.h"
 // Implementation 
ContactListener::ContactListener(){}

ContactListener::~ContactListener(){}

/***********************
* PreSolve: Checks if there will be a collision in the future and solve for it.
* @author: William de Beer
* @parameter: Contact information, Old world state.
********************/
void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    b2WorldManifold worldManifold;
    contact->GetWorldManifold(&worldManifold);

    b2PointState state1[2], state2[2];
    b2GetPointStates(state1, state2, oldManifold, contact->GetManifold());

    if (state2[0] == b2_addState) // if collsiion
    {
        // Get objects
        gameObject* objA = reinterpret_cast<gameObject*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        gameObject* objB = reinterpret_cast<gameObject*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
        
        // Get velocities
        b2Vec2 velocityA = objA->GetBody()->GetLinearVelocity();
        b2Vec2 velocityB = objB->GetBody()->GetLinearVelocity();
        float impactPower = sqrt(pow(velocityA.x - velocityB.x, 2) + pow(velocityA.y - velocityB.y, 2));

        if (impactPower > 5.0f) // Apply damage
        {
            objA->SetDurability(objA->GetDurability() - impactPower * objB->GetBody()->GetMass());
            objB->SetDurability(objB->GetDurability() - impactPower * objA->GetBody()->GetMass());
        }

        if (objA->GetLethal()) // Check if object is lethal
        {
            objB->SetDurability(-10.0f);
        }
        if (objB->GetLethal())
        {
            objA->SetDurability(-10.0f);
        }

        if (objA->GetDurability() <= 0.0f && objA->IsDestructable()
            || objB->GetDurability() <= 0.0f && objB->IsDestructable())
        {
            // Disable contact if either object is destroyed
            contact->SetEnabled(false);
            float slowMult = 0.8f;

            // Slow velocity
            if (!objA->GetLethal()) 
                objA->GetBody()->SetLinearVelocity(b2Vec2(velocityA.x * slowMult, velocityA.y * slowMult));
            if (!objB->GetLethal())
                objB->GetBody()->SetLinearVelocity(b2Vec2(velocityB.x * slowMult, velocityB.y * slowMult));
        }
    }
}
