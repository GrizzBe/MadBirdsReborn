#ifndef __CONTACT_LISTENER_H__
#define __CONTACT_LISTENER_H__

#include "ContactListener.h"
#include <iostream>

ContactListener::ContactListener()
{
}

ContactListener::~ContactListener()
{
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    b2WorldManifold worldManifold;
    contact->GetWorldManifold(&worldManifold);

    b2PointState state1[2], state2[2];
    b2GetPointStates(state1, state2, oldManifold, contact->GetManifold());

    if (state2[0] == b2_addState)
    {
        gameObject* objA = reinterpret_cast<gameObject*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        gameObject* objB = reinterpret_cast<gameObject*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
        
        b2Vec2 velocityA = objA->GetBody()->GetLinearVelocity();
        b2Vec2 velocityB = objB->GetBody()->GetLinearVelocity();
        float impactPower = sqrt(pow(velocityA.x - velocityB.x, 2) + pow(velocityA.y - velocityB.y, 2));

        if (impactPower > 5.0f)
        {
            objA->SetDurability(objA->GetDurability() - impactPower * objB->GetBody()->GetMass());
            objB->SetDurability(objB->GetDurability() - impactPower * objA->GetBody()->GetMass());
        }


        if (objA->GetLethal())
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
            contact->SetEnabled(false);
            float slowMult = 0.6f;

            if (!objA->GetLethal())
                objA->GetBody()->SetLinearVelocity(b2Vec2(velocityA.x * slowMult, velocityA.y * slowMult));
            if (!objB->GetLethal())
                objB->GetBody()->SetLinearVelocity(b2Vec2(velocityB.x * slowMult, velocityB.y * slowMult));
        }
    }
}

void ContactListener::BeginContact(b2Contact* contact)
{
	gameObject* objA = reinterpret_cast<gameObject*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	gameObject* objB = reinterpret_cast<gameObject*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

}

#endif