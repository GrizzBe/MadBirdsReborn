#ifndef __CHAIN_H__
#define __CHAIN_H__

#include "gameObject.h"

class Chain
{
public:
	Chain(b2Vec2 _pos, sf::Vector2f _scale, sf::Texture* _texture, b2World* _world, bool _destructable);
	~Chain();

	void Update(float _dT);
	void Draw(sf::RenderWindow& _window);
private:
	std::vector<gameObject*> m_ChainLinks;
};
#endif
