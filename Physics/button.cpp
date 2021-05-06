#include "button.h"

button::button(sf::Texture* _texture, sf::Vector2f _pos, bool _enabled, buttonFunction _function)
{
	m_Sprite = new sf::Sprite(*_texture);
	m_Sprite->setScale(0.7f, 0.7f);
	m_Sprite->setOrigin((sf::Vector2f)_texture->getSize() / 2.0f);
	m_Sprite->setPosition(_pos);

	m_bIsEnabled = _enabled;
	m_Function = _function;
}

button::~button()
{
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = 0;
	}
}

bool button::IsMouseIntersecting(sf::RenderWindow& _window)
{
	if (m_bIsEnabled)
	{
		if (m_Sprite->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(_window)))
		{
			m_Sprite->setColor(sf::Color(128, 255, 128));
			return true;
		}
		else
		{
			m_Sprite->setColor(sf::Color(255, 255, 255));
			return false;
		}
	}
	else
	{
		m_Sprite->setColor(sf::Color(128, 128, 128));
		return false;
	}
}

void button::Activate(sf::RenderWindow& _window)
{
	gameWorld* gW = nullptr;
	switch (m_Function)
	{
	case buttonFunction::level1:
		gW = new scene1();
		gW->MainLoop(_window);
		break;
	case buttonFunction::level2:
		gW = new scene2();
		gW->MainLoop(_window);
		break;
	case buttonFunction::level3:
		std::cout << "Level does not exist." << std::endl;
		break;
	case buttonFunction::level4:
		std::cout << "Level does not exist." << std::endl;
		break;
	case buttonFunction::quitGame:
		_window.close();
		break;
	default:
		std::cout << "Error actiavting button function." << std::endl;
		break;
	}

	if (gW != nullptr)
	{
		delete gW;
		gW = 0;
	}
}

sf::Sprite* button::GetSprite()
{
	return m_Sprite;
}

