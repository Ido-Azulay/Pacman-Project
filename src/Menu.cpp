#include "Menu.h"

const float BUTTON_SIZE_WIDTH = 600;
const float BUTTON_SIZE_HEIGHT = 100;

Menu::Menu()
{
	m_background.setTexture(&Resources::instace().getMenuTexture(t_Backround));
	m_background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGT));

	m_play_button.setTexture(&Resources::instace().getMenuTexture(t_Play));
	m_play_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
	m_play_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4), (WINDOW_HEIGT - 600)));

	m_exit_button.setTexture(&Resources::instace().getMenuTexture(t_Exit));
	m_exit_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
	m_exit_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4), (WINDOW_HEIGT - 220)));

	m_help_button.setTexture(&Resources::instace().getMenuTexture(t_Help));
	m_help_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
	m_help_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4), (WINDOW_HEIGT - 410)));


	m_back_button.setTexture(&Resources::instace().getMenuTexture(t_Back));
	m_back_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
	m_back_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4), (WINDOW_HEIGT - 220)));
	

	m_help_display.setTexture(&Resources::instace().getMenuTexture(t_helpBackround));
	m_help_display.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGT));

	m_gameOverDisplay.setTexture(&Resources::instace().getMenuTexture(t_Loose));
	m_gameOverDisplay.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGT));

	m_WinDisplay.setTexture(&Resources::instace().getMenuTexture(t_Win));
	m_WinDisplay.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGT));
}

Menu::~Menu()
{
}

char Menu::handleClick(const sf::Event::MouseButtonEvent& event , sf::RenderWindow& window)
{
	if (m_play_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		return PLAY;
	}

	if (m_exit_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		return EXIT;
	}

	if (m_help_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		m_draw_help = true;
		return HELP;
	}

	if (m_back_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		m_draw_help = false;
		return BACK;
	}

	return false;
}

void Menu::drawMenu(sf::RenderWindow &window)
{
	if (m_draw_help)
	{
		drawHelp(window);
	}
	else {
		window.draw(m_background);
		window.draw(m_play_button);
		window.draw(m_help_button);
		window.draw(m_exit_button);
	}

}

void Menu::drawHelp(sf::RenderWindow &window)
{
	window.draw(m_help_display);
	window.draw(m_back_button);
}

void Menu::displayLoose(sf::RenderWindow& window)
{
	window.draw(m_gameOverDisplay);
}

void Menu::displayWin(sf::RenderWindow& window)
{
	window.draw(m_WinDisplay);
}

bool Menu::getIsHelp()
{
	return m_draw_help;
}

void Menu::setIsHelp()
{
	m_draw_help = false;
}

