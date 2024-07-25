#pragma once
#include "MovingObject.h"



class Pacman : public MovingObject
{
public:
	Pacman();
	Pacman(sf::Vector2f pos);

	virtual void move(sf::Time delta, MovingVector& mov, StaticVector& stat) override;
	virtual void updateDirection(sf::Vector2f& obj , int num) {};
	virtual void setFreeze() {};
	virtual void stopFreeze() {};
	virtual void setSuper();
	virtual void stopSuper();

	virtual void handleCollison(Wall& obj);
	virtual void handleCollison(Pacman& obj) {};
	virtual void handleCollison(Key& obj);
	virtual void handleCollison(Cookie& obj);
	virtual void handleCollison(Ghost& obj);
	virtual void handleCollison(Door& obj);
	virtual void handleCollison(RandomGhost& obj);
	virtual void handleCollison(LifeGift& obj);
	virtual void handleCollison(TimeGift& obj);
	virtual void handleCollison(FreezeGift& obj);
	virtual void handleCollison(SuperGift& obj);
	virtual void handleCollison(OrangeGhost& obj);

	
	
	sf::Vector2f getOriginalPosition() const;

	void setOriginalPosition(sf::Vector2f pos);

	int getLives() const;
	int getScore() const;
	void setLives();
	void resetScore();




private:
	int m_lives = 3;
	int m_score = 0;
	std::vector<sf::Keyboard::Key> m_keyBoard;
	sf::Keyboard::Key getKeyPress() const;
	MovingObject::Direction keyToDirection(sf::Keyboard::Key key) const;

	void updateSprite();
	void CheckCollision(MovingVector& mov, StaticVector& stat);

	sf::Sound m_sound;
	bool m_super;
};
