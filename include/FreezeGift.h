#pragma once
#include "StaticObject.h"

class FreezeGift : public StaticObject
{
public:
	FreezeGift(const sf::Vector2f& pos);
	~FreezeGift();


	virtual void handleCollison(Wall& obj) {};
	virtual void handleCollison(Pacman& obj);
	virtual void handleCollison(Key& obj) {};
	virtual void handleCollison(Door& obj) {};
	virtual void handleCollison(Cookie& obj) {};
	virtual void handleCollison(Ghost& obj) {};
	virtual void handleCollison(RandomGhost& obj) {};
	virtual void handleCollison(LifeGift& obj) {};
	virtual void handleCollison(TimeGift& obj) {};
	virtual void handleCollison(FreezeGift& obj) {};
	virtual void handleCollison(OrangeGhost& obj) {};


private:

};

