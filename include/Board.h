#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <memory>
#include "ConstAndEnum.h"
#include "StaticObject.h"
#include "MovingObject.h"
#include "Pacman.h"
#include "TextAndFont.h"
#include "LifeGift.h"
#include "TimeGift.h"

class Board {
public:
	Board();
	~Board();
	void read_board(int level);
	void drawBoard(sf::RenderWindow& window) const;
	void updateBoard(const sf::Time& deltaTime);
	int getPacmanLives() const;
	int getNumOfCookies() const;
	int getBoardTime() ;
	void restartBoard();
	void resetPacLives();


	
private:
	sf::Vector2f CalculateFactor();
	void pacTeleport();
	void eraseDeletedObjects();
	TextAndFont m_text;

	sf::Vector2i m_boardSize;
	std::fstream m_inputFile;
	std::vector<std::string> m_board;

	//std::vector<Stat> 
	Pacman m_pacman;
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	
	float m_floatTimer = 3.f;
	float m_superTimer = 5.f;
	bool m_frozen = false;
	bool m_superMode = false;
};

