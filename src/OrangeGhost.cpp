#include "OrangeGhost.h"
#include "StaticObject.h"
#include "Pacman.h"

constexpr auto GhostSize = 50.f;
constexpr auto GhostSpeed = GhostSize * 4;


OrangeGhost::OrangeGhost(const sf::Vector2f& pos) : Ghost(pos)
{
	m_char = RANDGHOST;
	m_original_position = pos;
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_o));
	m_super = false;
}

OrangeGhost::~OrangeGhost()
{
}

void OrangeGhost::move(sf::Time deltaTime, MovingVector& mov, StaticVector& stat)
{
	m_stepSize = directionToVector(m_direction) * GhostSpeed * deltaTime.asSeconds();

	m_sprite.move(m_stepSize);

	for (auto& statobj : stat)
	{
		if (getBounds().intersects(statobj->getBounds()))
		{
			statobj->handleCollison(*this);
		}
	}
}

void OrangeGhost::updateDirection(sf::Vector2f& pac, int time)
{

	if (time % 2 == 0)
	{
		switch (time % 10)
		{
		case 0:
			m_direction = Direction::Right;
			break;
		case 1:
			m_direction = Direction::Down;
			break;
		case 2:
			m_direction = Direction::Left;
			break;
		case 3:
			m_direction = Direction::Up;
			break;
		case 4:
			m_direction = Direction::Down;
			break;
		case 5:
			m_direction = Direction::Left;
			break;

		case 6:
			m_direction = Direction::Right;
			break;
		case 7:
			m_direction = Direction::Up;
			break;

		case 8:
			m_direction = Direction::Left;
			break;

		case 9:
			m_direction = Direction::Down;
			break;
		default:
			m_direction = m_direction;
			break;
		}
	}

	else {
		switch (time % 5)
		{
		case 1:
			m_direction = Direction::Right;
			break;
		case 0:
			m_direction = Direction::Left;
			break;
		case 3:
			m_direction = Direction::Up;
			break;
		case 2:
			m_direction = Direction::Down;
			break;

		default:
			m_direction = Direction::Up;
			break;
		}
	}


	checkBoundries();
}

void OrangeGhost::checkBoundries()
{
	if (m_sprite.getPosition().y > 700)
	{
		m_direction = Direction::Up;
	}

	if (m_sprite.getPosition().y < 0)
	{
		m_direction = Direction::Down;

	}

	if (m_sprite.getPosition().x > 520)
	{
		m_direction = Direction::Left;
	}

	if (m_sprite.getPosition().x < 0)
	{
		m_direction = Direction::Right;
	}
}



void OrangeGhost::handleCollison(Wall& obj)
{
	m_sprite.move(-m_stepSize);
}


void OrangeGhost::handleCollison(Pacman& obj)
{
	m_sprite.setPosition(m_original_position);
	obj.handleCollison(*this);
}


void OrangeGhost::handleCollison(Door& obj)
{
	m_sprite.move(-m_stepSize);
}


void OrangeGhost::setFreeze()
{
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_fr));
}

void OrangeGhost::stopFreeze()
{
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_o));

}

void OrangeGhost::setSuper()
{
	m_super = true;
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Dead_ghost));

}

void OrangeGhost::stopSuper()
{
	m_super = false;

	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_o));

}



