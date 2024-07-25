#pragma once

#include "StaticObject.h"

class Cookie : public StaticObject
{
public:
	Cookie(const sf::Vector2f& pos);
	~Cookie();

	virtual void handleCollison(Wall& obj){};
	virtual void handleCollison(Pacman& obj);
	virtual void handleCollison(Key& obj) {};
	virtual void handleCollison(Cookie& obj) {};
	virtual void handleCollison(OrangeGhost& obj) {};

private:

};
