#include "Ghost.h"
#include "Pacman.h"
#include "StaticObject.h"


constexpr auto GhostSize = 50.f;
constexpr auto GhostSpeed = GhostSize * 4;

Ghost::Ghost(): MovingObject(Resources::instace().getTexture(Resources::t_Ghost)) {}

Ghost::Ghost(const sf::Vector2f& pos) : MovingObject(pos , Resources::instace().getTexture(Resources::t_Ghost)) {

	m_char = GHOST;
	m_original_position = pos;
}

Ghost::~Ghost() {}

void Ghost::move(sf::Time deltaTime, MovingVector& mov, StaticVector& stat)
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

void Ghost::updateDirection(sf::Vector2f& pac , int num)
{
	float xDiff = this->getPosition().x - pac.x;

	float yDiff = this->getPosition().y - pac.y;

	bool xdiffWasNeg = false;
	bool ydiffWasNeg = false;

	if (xDiff < 0)
	{
		xDiff *= -1;
		xdiffWasNeg = true;
	}

	if (yDiff < 0)
	{
		yDiff *= -1;
		ydiffWasNeg = true;
	}

	if (xDiff < yDiff)
	{
		if (xdiffWasNeg)
		{
			m_direction = Direction::Right;
		}

		else m_direction = Direction::Left;
	}
	else if (ydiffWasNeg)
	{
		m_direction = Direction::Down;
	}

	else m_direction = Direction::Up;

	if (xDiff < 0.5 && xDiff > -0.5)
	{
		if (getPosition().y < pac.y)
		{
			m_direction = Direction::Down;
		}
		else m_direction = Direction::Up;
	}

	if (yDiff < 0.5 && yDiff > -0.5)
	{
		if (getPosition().x < pac.x)
		{
			m_direction = Direction::Right;
		}
		else m_direction = Direction::Left;
	}

}


void Ghost::handleCollison(Wall& obj)
{
	m_sprite.move(-m_stepSize);
}

void Ghost::handleCollison(Pacman& obj)
{
	m_sprite.setPosition(m_original_position);
	obj.handleCollison(*this);
}


void Ghost::handleCollison(Ghost& obj)
{
	m_sprite.move(-m_stepSize);
}

void Ghost::handleCollison(Door& obj)
{
	m_sprite.move(-m_stepSize);
}

void Ghost::setFreeze()
{
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost_fr));
}

void Ghost::stopFreeze()
{
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost));

}

	
void Ghost::setSuper()
{
	m_super = true;
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Dead_ghost));

}

void Ghost::stopSuper()
{
	m_super = false;

	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Ghost));
}
