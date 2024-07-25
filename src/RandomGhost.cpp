#include "RandomGhost.h"
#include "StaticObject.h"
#include "Pacman.h"

constexpr auto GhostSize = 50.f;
constexpr auto GhostSpeed = GhostSize * 4;


RandomGhost::RandomGhost(const sf::Vector2f& pos) : Ghost(pos)
{
	m_char = RANDGHOST;
	m_original_position = pos;
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_r));
	m_super = false;
}

RandomGhost::~RandomGhost()
{
}

void RandomGhost::move(sf::Time deltaTime, MovingVector& mov, StaticVector& stat)
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

void RandomGhost::updateDirection(sf::Vector2f& pac , int time)
{

	if (time % 2 == 0)
	{
		switch (time % 5)
		{
		case 0:
			m_direction = Direction::Right;
			break;
		case 1:
			m_direction = Direction::Left;
			break;
		case 2:
			m_direction = Direction::Up;
			break;
		case 3:
			m_direction = Direction::Down;
			break;

		default:
			m_direction = Direction::Right;
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

void RandomGhost::checkBoundries()
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



void RandomGhost::handleCollison(Wall& obj)
{
	m_sprite.move(-m_stepSize);
}


void RandomGhost::handleCollison(Pacman& obj)
{
	m_sprite.setPosition(m_original_position);
	obj.handleCollison(*this);
}


void RandomGhost::handleCollison(Door& obj)
{
	m_sprite.move(-m_stepSize);
}


void RandomGhost::setFreeze()
{
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_fr));
}

void RandomGhost::stopFreeze()
{
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_r));

}

void RandomGhost::setSuper()
{
	m_super = true;
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Dead_ghost));

}

void RandomGhost::stopSuper()
{
	m_super = false;

	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_r));

}
