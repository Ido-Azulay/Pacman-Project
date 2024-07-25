#include "Door.h"
#include "Ghost.h"
#include "Pacman.h"
#include "RandomGhost.h"
#include "OrangeGhost.h"

Door::Door(const sf::Vector2f& pos) : StaticObject(pos , Resources::instace().getTexture(Resources::t_Door))
{
	m_char = DOOR;
}

Door::~Door(){}

void Door::handleCollison(Pacman& obj)
{
	obj.handleCollison(*this);
}

void Door::handleCollison(Ghost& obj)
{
	obj.handleCollison(*this);
}

void Door::handleCollison(RandomGhost& obj)
{
	obj.handleCollison(*this);
}

void Door::handleCollison(OrangeGhost& obj)
{
	obj.handleCollison(*this);
}

