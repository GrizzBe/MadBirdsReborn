#ifndef __SCENE2_H__
#define __SCENE2_H__
#include "gameWorld.h"
class scene2 :
    public gameWorld
{
public:
    scene2();
    virtual ~scene2();

    virtual void Update(float _dT);
    virtual void Render(sf::RenderWindow& _window);
    virtual void GenerateLevel(b2World& _world);
    virtual void DestroyBox2DObjects();
private:
    Chain* m_Chain1;
    prismatic* m_Prismatic;
};

#endif