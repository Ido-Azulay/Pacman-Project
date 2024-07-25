#include "LifeGift.h"
#include "Pacman.h"


LifeGift::LifeGift(const sf::Vector2f & pos) : StaticObject(pos, Resources::instace().getTexture(Resources::t_LifeGift))
{

}

LifeGift::~LifeGift()
{

}

void LifeGift::handleCollison(Pacman& obj)
{
	m_isDisposed = true;
	obj.handleCollison(*this);
}