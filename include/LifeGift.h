#pragma once
#include "StaticObject.h"

class LifeGift : public StaticObject
{
public:
	LifeGift(const sf::Vector2f& pos);
	~LifeGift();


	virtual void handleCollison(Wall& obj) {};
	virtual void handleCollison(Pacman& obj) ;
	virtual void handleCollison(Key& obj) {};
	virtual void handleCollison(Door& obj) {};
	virtual void handleCollison(Cookie& obj) {};
	virtual void handleCollison(Ghost& obj) {};
	virtual void handleCollison(RandomGhost& obj) {};
	virtual void handleCollison(LifeGift& obj) {};
	

private:

};

