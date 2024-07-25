#include "Wall.h"
#include "Pacman.h"
#include "Ghost.h"
#include "RandomGhost.h"
#include "OrangeGhost.h"


Wall::Wall(const sf::Vector2f& pos) : StaticObject(pos, Resources::instace().getTexture(Resources::t_Wall))
{
	m_char = WALL;
}

Wall::~Wall(){}


void Wall::handleCollison(Pacman& obj)
{
	obj.handleCollison(*this);
}


void Wall::handleCollison(Ghost& obj)
{
	obj.handleCollison(*this);
}


void Wall::handleCollison(RandomGhost& obj)
{
	obj.handleCollison(*this);
}

void Wall::handleCollison(OrangeGhost& obj)
{
	obj.handleCollison(*this);
}