#include "Pacman.h"
#include "StaticObject.h"
#include "RandomGhost.h"
#include <iostream>

constexpr auto PacmanSize = 50.f;
constexpr auto PacmanSpeed = PacmanSize * 4;

Pacman::Pacman() : m_keyBoard({ sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down, sf::Keyboard::Left })
{
	m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Pacman_r));
	m_char = 'a';
	m_super = false;
}

Pacman::Pacman(sf::Vector2f pos) : Pacman() //reuse default constructor
{
	m_sprite.setPosition(pos);
	m_char = 'a';
	
}

void Pacman::move(sf::Time deltaTime, MovingVector& mov, StaticVector& stat)
{
	m_direction = keyToDirection(getKeyPress());
	
	updateSprite();

	m_stepSize = directionToVector(m_direction) * PacmanSpeed * deltaTime.asSeconds();
	
	m_sprite.move(m_stepSize);

	std::cout << m_sprite.getPosition().x << " \n";

	CheckCollision(mov, stat);

}

sf::Keyboard::Key Pacman::getKeyPress() const
{
	for (int i = 0; i < m_keyBoard.size(); i++)
		if (sf::Keyboard::isKeyPressed(m_keyBoard[i]))
			return m_keyBoard[i];

	return sf::Keyboard::Key();
}

MovingObject::Direction Pacman::keyToDirection(sf::Keyboard::Key key) const
{
	switch (key)
	{
	case sf::Keyboard::Left:
		return Direction::Left;
	case sf::Keyboard::Right:
		return Direction::Right;
	case sf::Keyboard::Up:
		return Direction::Up;
	case sf::Keyboard::Down:
		return Direction::Down;
	default:
		return m_direction; //if want to play like original return m_direction //for project return Direction::Stay 
	}
	return Direction::Stay;
}

sf::Vector2f Pacman::getOriginalPosition() const
{
	return m_original_position;
}


void Pacman::setOriginalPosition(sf::Vector2f pos)
{
	m_original_position = pos;
}



int Pacman::getLives() const
{
	return m_lives;
}

void Pacman::setLives()
{
	m_lives = 3;
}




void Pacman::setSuper()
{
	m_super = true;

}

void Pacman::stopSuper()
{
	m_super = false;


}




void Pacman::updateSprite()
{
	if (m_super)
	{
		if (m_direction == Direction::Up)
		{
			m_sprite.setTexture(Resources::instace().getTexture(Resources::t_SPacman_u));
		}

		if (m_direction == Direction::Down)
		{
			m_sprite.setTexture(Resources::instace().getTexture(Resources::t_SPacman_d));
		}

		if (m_direction == Direction::Left)
		{
			m_sprite.setTexture(Resources::instace().getTexture(Resources::t_SPacman_l));
		}

		if (m_direction == Direction::Right)
		{
			m_sprite.setTexture(Resources::instace().getTexture(Resources::t_SPacman_r));
		}
	}
	else 
	{

		if (m_direction == Direction::Up)
		{
			m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Pacman_u));
		}

		if (m_direction == Direction::Down)
		{
			m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Pacman_d));
		}

		if (m_direction == Direction::Left)
		{
			m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Pacman_l));
		}

		if (m_direction == Direction::Right)
		{
			m_sprite.setTexture(Resources::instace().getTexture(Resources::t_Pacman_r));
		}
	}
}


void Pacman::CheckCollision(MovingVector& mov, StaticVector& stat)
{

	for (auto& statobj : stat)
	{
		if (getBounds().intersects(statobj->getBounds()))
		{
			statobj->handleCollison(*this);
		}
	}
	for (auto& moving : mov)
	{
		if (getBounds().intersects(moving->getBounds()))
		{
			if (moving->getChar() == GHOST)
			{
				for (auto& movingg : mov)
				{
					movingg->setOriginalPosition(movingg->getOriginalPosition());
				}
			}
			moving->handleCollison(*this);
		
		}
	}

}

int Pacman::getScore() const
{
	return m_score;
}


void Pacman::resetScore()
{
	m_score = 0;
}


///////////////////////////////////////////////////////////////////////////
//***********/////////         COLISSION HANDLE          //////////******//


void Pacman::handleCollison(RandomGhost& obj)
{

	if (m_super)
	{
		m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Eat_demon));
		m_sound.play();
		m_score += 10;
	}

	else {

		if (m_lives <= 1)
		{
			m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Pacman_dead));
		}
		else m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_hit_ghost));

		m_sound.play();

		m_lives--;

		m_sprite.setPosition(m_original_position);
	}

}

void Pacman::handleCollison(OrangeGhost& obj)
{

	if (m_super)
	{
		m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Eat_demon));
		m_sound.play();
		m_score += 10;
	}

	else {

		if (m_lives <= 1)
		{
			m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Pacman_dead));
		}
		else m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_hit_ghost));

		m_sound.play();

		m_lives--;

		m_sprite.setPosition(m_original_position);
	}

}

void Pacman::handleCollison(LifeGift& obj)
{
	m_lives++;

	m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Gift));

	m_sound.setVolume(100);

	m_sound.setLoop(false);

	m_sound.play();

	m_score += 5;
}


void Pacman::handleCollison(TimeGift& obj)
{

	m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Gift));

	m_sound.setVolume(100);

	m_sound.setLoop(false);

	m_sound.play();

	m_score += 5;
}

void Pacman::handleCollison(SuperGift& obj)
{

	m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Gift));

	m_sound.setVolume(100);

	m_sound.setLoop(false);

	m_sound.play();

	m_score += 5;

	
}



void Pacman::handleCollison(Door& obj)
{
	m_sprite.move(-m_stepSize);
}


void Pacman::handleCollison(Cookie& obj)
{

	m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Eat_cookie));

	m_sound.setVolume(100);

	m_sound.setLoop(false);

	m_sound.play();

	m_score += 2;
}

void Pacman::handleCollison(Key& obj)
{

	m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Eat_key));

	m_sound.setVolume(100);

	m_sound.setLoop(false);

	m_sound.play();

	m_score += 7;
}

void Pacman::handleCollison(FreezeGift& obj)
{

	m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Gift));

	m_sound.setVolume(100);

	m_sound.setLoop(false);

	m_sound.play();

	m_score += 5;
}



void Pacman::handleCollison(Wall& obj)
{

	m_sprite.move(-m_stepSize);
}

void Pacman::handleCollison(Ghost& obj)
{

	if (m_super)
	{
		m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Eat_demon));
		m_sound.play();
		m_score += 10;
	}

	else 
	{
		if (m_lives <= 1)
		{
			m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Pacman_dead));
		}
		else m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_hit_ghost));

		m_sound.play();

		m_lives--;

		m_sprite.setPosition(m_original_position);

	}
}
