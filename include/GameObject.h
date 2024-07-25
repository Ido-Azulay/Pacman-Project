#pragma once
#include "Resources.h"
#include "ConstAndEnum.h"
#include <SFML/Graphics.hpp>

class MovingObject;
class StaticObject;
class Pacman;
class Wall;
class Key;
class Cookie;
class Ghost;
class RandomGhost;
class OrangeGhost;
class Door;
class LifeGift;
class TimeGift;
class FreezeGift;
class SuperGift;


class GameObject
{
public:
	GameObject();
	GameObject(const sf::Texture& tex);
	GameObject(const sf::Vector2f& pos , const sf::Texture& tex);

	void setScale(const sf::Vector2f &scale);

	~GameObject() = default;

	void drawObject(sf::RenderWindow& window) const;

	void setPosition(sf::Vector2f pos);

	sf::Vector2f getPosition() const;
	char getChar() const;

	sf::FloatRect getBounds() const;

	void handleCollison(GameObject &obj);
	virtual void handleCollison(Wall &obj){};
	virtual void handleCollison(Pacman &obj){};
	virtual void handleCollison(Key &obj){};
	virtual void handleCollison(Door &obj){};
	virtual void handleCollison(Cookie &obj){};
	virtual void handleCollison(Ghost& obj) {};
	virtual void handleCollison(RandomGhost& obj){};
	virtual void handleCollison(OrangeGhost& obj){};
	virtual void handleCollison(LifeGift& obj){};
	virtual void handleCollison(TimeGift& obj) {};
	virtual void handleCollison(FreezeGift& obj) {};
	virtual void handleCollison(SuperGift& obj) {};




protected:
	sf::Sprite m_sprite;
	char m_char;
};

