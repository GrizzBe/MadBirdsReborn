
#include <box2d.h>
#include "b2_world_callbacks.h"
#include "gameObject.h"
#include "bird.h"

class ContactListener :
    public b2ContactListener
{
public:
    ContactListener();
    virtual ~ContactListener();

    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    
    virtual void BeginContact(b2Contact* contact);
private:
};

