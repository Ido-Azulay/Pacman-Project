#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGT), "Pacman")
{
	m_board.read_board(m_level);
}

void Controller::RunGame()
{
	srand(static_cast<unsigned>(time(nullptr)));
	m_clock.restart(); //saves bugs
	

	while (m_window.isOpen())
	{
		if (m_board.getPacmanLives() <= 0)
		{
			m_window.clear();
			m_menu.displayLoose(m_window);
			m_window.display();

			auto pause = std::chrono::high_resolution_clock::now();
			std::this_thread::sleep_for(std::chrono::seconds(2));

			//**** bugFixes
			m_level = 1;
			m_board.restartBoard();
			m_board.resetPacLives();
			m_board.read_board(m_level);
			//**** bugFixes
			return;
		}

		if (m_board.getBoardTime() <= 0)
		{
			m_window.clear();
			m_menu.displayLoose(m_window);
			m_window.display();

			auto pause = std::chrono::high_resolution_clock::now();
			std::this_thread::sleep_for(std::chrono::seconds(2));

			//**** bug fixes
			m_level = 1;
			m_board.restartBoard();
			m_board.resetPacLives();
			m_board.read_board(m_level);
			//**** bug fixes
			return;
		}

		if(m_board.getNumOfCookies() == 0)
		{
			m_window.clear();

			m_level++;


			if (m_level == 4)
			{
				m_window.clear();

				m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Win_stage));

				m_sound.play();

				m_menu.displayWin(m_window);
				m_window.display();

				auto pause = std::chrono::high_resolution_clock::now();
				std::this_thread::sleep_for(std::chrono::seconds(2));
				
				m_level = 1;

				m_board.restartBoard();

				m_board.read_board(m_level);
				//display win image
				return;
			}

			m_board.restartBoard();
			
			m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Start_music));

			m_sound.play();

			m_board.read_board(m_level);

			continue;

		}

		drawBoard();
		updateBoard();

		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
	}
}

void Controller::drawBoard()
{
	m_window.clear();
	m_board.drawBoard(m_window);
	m_window.display();
}

void Controller::updateBoard()
{
	auto deltaTime = m_clock.restart();
	m_board.updateBoard(deltaTime);
	
}

void Controller::Run()
{
	srand(static_cast<unsigned>(time(nullptr)));

	m_clock.restart(); //saves bugs

	m_sound.setBuffer(Resources::instace().getSound(Resources::Sounds::s_Start_music));

	m_sound.setVolume(100);

	m_sound.setLoop(false);

	m_sound.play();

	while (m_window.isOpen())
	{
		
		m_window.clear();
		m_menu.drawMenu(m_window);
		m_window.display();

		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonReleased:
				char c = m_menu.handleClick(event.mouseButton, m_window);

				if (c == PLAY)
				{
					RunGame();
				}
				if (c == EXIT)
				{
					if (m_menu.getIsHelp())
					{
						m_menu.setIsHelp();
					}
					else  m_window.close();
				}

				break;
			}
		}

	}
	
}

