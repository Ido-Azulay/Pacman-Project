#include "SuperGift.h"
#include "Pacman.h"


SuperGift::SuperGift(const sf::Vector2f& pos) : StaticObject(pos, Resources::instace().getTexture(Resources::t_SuperGift))
{
	m_char = SUPER_GIFT;
}

SuperGift::~SuperGift()
{

}

void SuperGift::handleCollison(Pacman& obj)
{
	m_isDisposed = true;
	obj.handleCollison(*this);
}