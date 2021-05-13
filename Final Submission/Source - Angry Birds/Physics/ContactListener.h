#ifndef __CONTACT_LISTENER_H__
#define __CONTACT_LISTENER_H__
// 
//  Bachelor of Software Engineering 
//  Media Design School 
//  Auckland 
//  New Zealand 
// 
//  (c) 2021 Media Design School 
// 
//  File Name   :   ContactListener.h
//  Description :   Registers contacts between box2D objects.
//  Author      :   William de Beer
//  Mail        :   William.Beer@mds.ac.nz
// 
 // Library Includes 
#include <box2d.h>
#include "b2_world_callbacks.h"
 // Local Includes 
#include "gameObject.h"
#include "bird.h"
 // Implementation 
class ContactListener :
    public b2ContactListener
{
public:
    ContactListener();
    virtual ~ContactListener();

    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
private:
};

#endif