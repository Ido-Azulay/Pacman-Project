#pragma once 

#include "StaticObject.h"

class Key :public StaticObject
{
public:
	Key(const sf::Vector2f& pos);
	~Key();

	virtual void handleCollison(Wall& obj) {};
	virtual void handleCollison(Pacman& obj);
	virtual void handleCollison(Key& obj) {};
	virtual void handleCollison(OrangeGhost& obj) {};

private:

};
