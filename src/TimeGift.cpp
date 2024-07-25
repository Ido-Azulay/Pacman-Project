#include "TimeGift.h"
#include "Pacman.h"


TimeGift::TimeGift(const sf::Vector2f& pos) : StaticObject(pos, Resources::instace().getTexture(Resources::t_TimeGift))
{
	m_char = TIME_GIFT;
}

TimeGift::~TimeGift()
{

}

void TimeGift::handleCollison(Pacman& obj)
{
	m_isDisposed = true;
	obj.handleCollison(*this);
}