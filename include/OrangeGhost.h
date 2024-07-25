#pragma once
#include "Ghost.h"
#include "MovingObject.h"

class OrangeGhost : public Ghost
{
public:
	OrangeGhost(const sf::Vector2f& pos);
	~OrangeGhost();

	virtual void move(sf::Time delta, MovingVector&, StaticVector&) override;
	virtual void updateDirection(sf::Vector2f& obj , int time) override;
	virtual void setFreeze();
	virtual void stopFreeze();
	virtual void setSuper();
	virtual void stopSuper();
	

	virtual void handleCollison(Wall& obj);
	virtual void handleCollison(Pacman& obj);
	virtual void handleCollison(Key& obj) {};
	virtual void handleCollison(Cookie& obj) {};
	virtual void handleCollison(Ghost& obj){};
	virtual void handleCollison(Door& obj);

private:
	void checkBoundries();
	bool m_super = false;
};
