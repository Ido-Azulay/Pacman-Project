#pragma once
#include "MovingObject.h"


class Ghost : public MovingObject
{
public:
	Ghost();
	Ghost(const sf::Vector2f &pos);
	~Ghost();

	virtual void move(sf::Time delta, MovingVector&, StaticVector&) override;
	virtual void updateDirection(sf::Vector2f& obj , int num) override;
	virtual void setFreeze();
	virtual void stopFreeze();
	virtual void setSuper();
	virtual void stopSuper();

	virtual void handleCollison(Wall& obj);
	virtual void handleCollison(Pacman& obj);
	virtual void handleCollison(Key& obj) {};
	virtual void handleCollison(Cookie& obj) {};
	virtual void handleCollison(Ghost& obj);
	virtual void handleCollison(Door& obj);
	virtual void handleCollison(OrangeGhost& obj) {};

	protected:
		sf::Vector2f m_original_position;

private:
	bool m_super = false;

};

