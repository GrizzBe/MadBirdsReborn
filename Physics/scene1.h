#ifndef __SCENE1_H__
#define __SCENE1_H__
#include "gameWorld.h"
class scene1 :
    public gameWorld
{
public:
    scene1();
    virtual ~scene1();

    virtual void Update(float _dT);
    virtual void Render(sf::RenderWindow& _window);
    virtual void GenerateLevel(b2World& _world);
    virtual void DestroyBox2DObjects();
private:
    Chain* m_Chain1;
    seesaw* m_Seesaw1;
};

#endif