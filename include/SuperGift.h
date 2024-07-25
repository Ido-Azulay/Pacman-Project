#pragma once
#include "StaticObject.h"

class SuperGift : public StaticObject
{
public:
	SuperGift(const sf::Vector2f& pos);
	~SuperGift();


	virtual void handleCollison(Wall& obj) {};
	virtual void handleCollison(Pacman& obj);
	virtual void handleCollison(Key& obj) {};
	virtual void handleCollison(Door& obj) {};
	virtual void handleCollison(Cookie& obj) {};
	virtual void handleCollison(Ghost& obj) {};
	virtual void handleCollison(RandomGhost& obj) {};
	virtual void handleCollison(LifeGift& obj) {};
	virtual void handleCollison(TimeGift& obj) {};
	virtual void handleCollison(SuperGift& obj) {};
	virtual void handleCollison(OrangeGhost& obj) {};


private:

};

