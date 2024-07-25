#include "Key.h"
#include "Pacman.h"

Key::Key(const sf::Vector2f& pos) : StaticObject(pos, Resources::instace().getTexture(Resources::t_Key)) {

	m_char = KEY;
}


Key::~Key()
{
}


void Key::handleCollison(Pacman& obj)
{
	m_isDisposed = true;

	obj.handleCollison(*this);

}