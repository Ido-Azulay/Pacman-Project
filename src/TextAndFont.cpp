#include "TextAndFont.h"
#include "Resources.h"


TextAndFont::TextAndFont()
{
	m_clock.setFont(Resources::instace().getFont());
	m_clock.setCharacterSize(60);
	m_clock.setFillColor(sf::Color::Yellow);
	m_clock.setPosition(sf::Vector2f((WINDOW_WIDTH / 4) + 200, (WINDOW_HEIGT - 135)));
	m_clock.setString("4:20"); 

	m_lives.setFont(Resources::instace().getFont());
	m_lives.setCharacterSize(60);
	m_lives.setFillColor(sf::Color::Yellow);
	m_lives.setPosition(sf::Vector2f((WINDOW_WIDTH / 4) + 500, (WINDOW_HEIGT - 135)));
	m_lives.setString("Lives: ");

	m_lives_num.setFont(Resources::instace().getFont());
	m_lives_num.setCharacterSize(60);
	m_lives_num.setFillColor(sf::Color::Yellow);
	m_lives_num.setPosition(sf::Vector2f((WINDOW_WIDTH / 4) + 710, (WINDOW_HEIGT - 135)));
	m_lives_num.setString("3");


	m_score.setFont(Resources::instace().getFont());
	m_score.setCharacterSize(60);
	m_score.setFillColor(sf::Color::Yellow);
	m_score.setPosition(sf::Vector2f(10, (WINDOW_HEIGT - 135)));
	m_score.setString("score:");

	m_score_num.setFont(Resources::instace().getFont());
	m_score_num.setCharacterSize(60);
	m_score_num.setFillColor(sf::Color::Yellow);
	m_score_num.setPosition(sf::Vector2f(220, (WINDOW_HEIGT - 135)));
	m_score_num.setString("0");
}

TextAndFont::~TextAndFont()
{
	
}


void TextAndFont::setLives(int num)
{
	std::string str = std::to_string(num);
	
	m_lives_num.setString(str);
}


void TextAndFont::setScore(int num)
{
	std::string str = std::to_string(num);
	
	m_score_num.setString(str);
}


void TextAndFont::draw(sf::RenderWindow& window) const
{
	window.draw(m_clock);
	window.draw(m_score);
	window.draw(m_score_num);
	window.draw(m_lives);
	window.draw(m_lives_num);

}

int TextAndFont::getTime()
{
	float elapse = 90 - round(m_clock_num.getElapsedTime().asSeconds());

	int num = elapse;

	return num;
}




void TextAndFont::resetTime()
{
	m_resetTime = true;
	m_increaseTime = false;
}




void TextAndFont::setTime()
{
	static sf::Clock clock;

	if (m_resetTime)
	{
		clock.restart();
		m_resetTime = false;
	}

	m_clock_num = clock;

	float elapse = 90 - round(clock.getElapsedTime().asSeconds());
	
	if (m_increaseTime)
	{
		elapse += 30.0;
		//m_increaseTime = false;
	}

	int num = elapse;

	std::string str = std::to_string(num);

	m_clock.setString(str);
}

void TextAndFont::increaseTime()
{
	m_increaseTime = true;
}