#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Board.h"
#include "Resources.h"
#include "MovingObject.h"
#include "Pacman.h"
#include "Menu.h"
#include <thread>
#include <chrono>


class Controller
{
public: 
	Controller();
	void Run();
	void RunGame();


private:
	void drawBoard();
	void updateBoard();


	sf::RenderWindow m_window;
	sf::Clock m_clock;
	Board m_board;
	Menu m_menu;
	sf::Sound m_sound;

	int m_level = 1;
};