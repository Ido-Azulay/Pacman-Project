#include "Board.h"
#include "iostream"
#include "Ghost.h"
#include "RandomGhost.h"
#include "Wall.h"
#include "Door.h"
#include "Cookie.h"
#include "Key.h"
#include "TimeGift.h"
#include "FreezeGift.h"
#include "SuperGift.h"
#include <iostream>
#include "OrangeGhost.h"

Board::Board() :m_inputFile("Level1.txt")
{

	if (!m_inputFile.is_open())
	{
		std::cerr << "could'nt open board text file\n";
		exit(EXIT_FAILURE);
	}

	m_inputFile.close();
	
}

//==============================================================
//distructor
Board::~Board()
{
	m_inputFile.close();
}

//==============================================================


void Board::restartBoard()
{
	m_movingObjects.clear();
	m_staticObjects.clear();
	m_board.clear();

	//scale factor because eachtime we restart the game read board set scalse to pacman
	//and makes it smaller and smaller , this is the fix
	sf::Vector2f scaleFactor = CalculateFactor();
	scaleFactor.x = 1 / scaleFactor.x;
	scaleFactor.y = 1 / scaleFactor.y;
	m_pacman.setScale(scaleFactor);
	m_text.resetTime();
	m_text.setTime();
}




//this function reads the board from the text file the first time
void Board::read_board(int level)
{
	m_floatTimer = 0.5;
	m_superMode = false;
	m_pacman.stopSuper();
	m_frozen = true;
	m_superTimer = 5.f;

	if (level == 1)
	{
		m_inputFile.open("Level1.txt");
	}

	if (level == 2)
	{
		m_inputFile.open("Level2.txt");
	}

	if (level == 3)
	{
		m_inputFile.open("Level3.txt");
	}

	m_board.clear();

	m_inputFile >> m_boardSize.x >> m_boardSize.y;

	m_inputFile.get(); //take endl after row and coll

	for (int i = 0; i < m_boardSize.y; i++)
	{
		std::string line;
		std::getline(m_inputFile, line);
		m_board.push_back(line);
	}
	//can take this loop to a different function
	sf::Vector2f pos;
	sf::Vector2f scaleFactor = CalculateFactor();

	m_inputFile.close();
	
	for (int i = 0; i < m_board.size(); i++) {
		for (int j = 0; j < m_board[i].size(); j++) {

			pos = sf::Vector2f( j*SPRITE_SIZE, i*SPRITE_SIZE);
			pos *= scaleFactor.x;

			switch (m_board[i][j])
			{
			case(PACMAN):
				m_pacman.setPosition(pos);
				m_pacman.setOriginalPosition(pos);
				m_pacman.setScale(scaleFactor);

				break;
			case(GHOST):
				m_movingObjects.push_back(std::make_unique<Ghost>(pos));
				
				m_movingObjects.back()->setScale(scaleFactor);
				break;

			case(RANDGHOST):
				m_movingObjects.push_back(std::make_unique<RandomGhost>(pos));

				m_movingObjects.back()->setScale(scaleFactor);
				break;

			case(ORANGEGHOST):
				m_movingObjects.push_back(std::make_unique<OrangeGhost>(pos));

				m_movingObjects.back()->setScale(scaleFactor);
				break;

			case(WALL):
				m_staticObjects.push_back(std::make_unique<Wall>(pos));
				m_staticObjects.back()->setScale(scaleFactor);
				break;
			case(DOOR):
				m_staticObjects.push_back(std::make_unique<Door>(pos));
				m_staticObjects.back()->setScale(scaleFactor);
				break;
			case(COOKIE):
				m_staticObjects.push_back(std::make_unique<Cookie>(pos));
				m_staticObjects.back()->setScale(scaleFactor);
				//m_staticObjects.back().get().
				break;
			case(KEY):
				m_staticObjects.push_back(std::make_unique<Key>(pos));
				m_staticObjects.back()->setScale(scaleFactor);
				break;
			case(LIFE_GIFT):
				m_staticObjects.push_back(std::make_unique<LifeGift>(pos));
				m_staticObjects.back()->setScale(scaleFactor);
				break;

			case(TIME_GIFT):
				m_staticObjects.push_back(std::make_unique<TimeGift>(pos));
				m_staticObjects.back()->setScale(scaleFactor);
				break;

			case(FREEZE_GIFT):
				m_staticObjects.push_back(std::make_unique<FreezeGift>(pos));
				m_staticObjects.back()->setScale(scaleFactor);
				break;
			case(SUPER_GIFT):
				m_staticObjects.push_back(std::make_unique<SuperGift>(pos));
				m_staticObjects.back()->setScale(scaleFactor);
				break;

			default:
				break;
			}
		}
	}
}

void Board::drawBoard(sf::RenderWindow& window) const
{
	for (auto& mov : m_movingObjects)
	{
		mov->drawObject(window);
	}

	for (auto& stat : m_staticObjects)
	{
		stat->drawObject(window);
	}

	m_pacman.drawObject(window);

	m_text.draw(window);
}

void Board::updateBoard(const sf::Time& deltaTime)
{
	m_text.setLives(m_pacman.getLives());
	m_text.setScore(m_pacman.getScore());
	m_text.setTime();

	int time = m_text.getTime();

		m_pacman.move(deltaTime, m_movingObjects, m_staticObjects);

		pacTeleport();

		if (m_superMode)
		{
			m_superTimer -= deltaTime.asSeconds();

			if (m_superTimer <= 0) 
			{
				m_superMode = false;
				m_pacman.stopSuper();
				for (auto& mov : m_movingObjects)
				{
					mov->stopSuper();
				}
				m_superTimer = 5.f;
			}
		}

	if (m_frozen)
	{
		for (auto& mov : m_movingObjects)
		{
			mov->setFreeze();
		}
		m_floatTimer -= deltaTime.asSeconds();

		if (m_floatTimer <= 0) 
		{
			m_frozen = false;
			for (auto& mov : m_movingObjects)
			{
				mov->stopFreeze();
			}
			m_floatTimer = 3.f;
		}
	}
	else {
		for (auto& mov : m_movingObjects)
		{
			sf::Vector2f pos = m_pacman.getPosition();

			mov->updateDirection(pos, time);

			mov->move(deltaTime, m_movingObjects, m_staticObjects);
		}
	}
	
	eraseDeletedObjects();

}

sf::Vector2f Board::CalculateFactor()
{

	sf::Vector2f scaleFactor;
	float heigt = (WINDOW_HEIGT - 280);
	float width = WINDOW_WIDTH;
	scaleFactor.x = std::min(heigt / (m_boardSize.x * SPRITE_SIZE), width / (m_boardSize.y * SPRITE_SIZE));
	scaleFactor.y = scaleFactor.x;

	std::cout << scaleFactor.y << "\n";

	return scaleFactor;
}



void Board::eraseDeletedObjects()
{

	bool foundDoor = false;

	for (auto& obj : m_staticObjects)
	{
		if (obj->getChar() == KEY && obj->get_is_disposed())
		{
			for (auto& objDoor : m_staticObjects)
			{
				if (objDoor->getChar() == DOOR)
				{
					objDoor->set_is_disposed();
					foundDoor = true;

					break;
				}
			}
		}

		if (foundDoor == true)
		{
			break;
		}

		if (obj->getChar() == TIME_GIFT && obj->get_is_disposed())
		{
			m_text.increaseTime();
			break;
		}

		if (obj->getChar() == FREEZE_GIFT && obj->get_is_disposed())
		{
			m_frozen = true;
			break;
		}

		if (obj->getChar() == SUPER_GIFT && obj->get_is_disposed())
		{
			m_superMode = true;
			for (auto& mov : m_movingObjects)
			{
				mov->setSuper();
			}
			m_pacman.setSuper();
			break;
		}
	}

	std::erase_if(m_staticObjects, [](const auto& item) {return item->get_is_disposed(); });
}

int Board::getPacmanLives() const
{
	return m_pacman.getLives();
}

int Board::getNumOfCookies() const
{
	int counter = 0;

	for (auto& obj : m_staticObjects)
	{
		if (obj->getChar() == COOKIE)
		{
			counter++;
		}
	}

	return counter;
}



void Board::pacTeleport()
{
	if (m_pacman.getPosition().y > (m_boardSize.y * SPRITE_SIZE * CalculateFactor().y))
	{
		sf::Vector2f pos;
		pos.x = m_pacman.getPosition().x;
		pos.y = 0;
		m_pacman.setPosition(pos);
	}

	if (m_pacman.getPosition().y < 0)
	{
		sf::Vector2f pos;
		pos.x = m_pacman.getPosition().x;
		pos.y = m_boardSize.y * SPRITE_SIZE * CalculateFactor().y;
		m_pacman.setPosition(pos);
	}

	if (m_pacman.getPosition().x > (m_boardSize.x * SPRITE_SIZE * CalculateFactor().x))
	{
		sf::Vector2f pos;
		pos.y = m_pacman.getPosition().y;
		pos.x = 0;
		m_pacman.setPosition(pos);
	}

	if (m_pacman.getPosition().x < 0)
	{
		sf::Vector2f pos;
		pos.y = m_pacman.getPosition().y;
		pos.x = m_boardSize.x * SPRITE_SIZE * CalculateFactor().x;
		m_pacman.setPosition(pos);
	}
}


void Board::resetPacLives()
{
	m_pacman.setLives();
	m_pacman.resetScore();
}


int Board::getBoardTime() 
{
	return m_text.getTime();
}