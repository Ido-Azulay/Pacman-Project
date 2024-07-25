#include "FreezeGift.h"
#include "Pacman.h"


FreezeGift::FreezeGift(const sf::Vector2f& pos) : StaticObject(pos, Resources::instace().getTexture(Resources::t_FreezeGift))
{
	m_char = FREEZE_GIFT;
}

FreezeGift::~FreezeGift()
{

}

void FreezeGift::handleCollison(Pacman& obj)
{
	m_isDisposed = true;
	obj.handleCollison(*this);
}