#include "Cookie.h"
#include "Pacman.h"

Cookie::Cookie(const sf::Vector2f& pos) : StaticObject(pos, Resources::instace().getTexture(Resources::t_Cookie)) {

	sf::Vector2f point = m_sprite.getPosition();
	m_char = COOKIE;
}


Cookie::~Cookie()
{
}


void Cookie::handleCollison(Pacman& obj)
{
	m_isDisposed = true;

	obj.handleCollison(*this);
}