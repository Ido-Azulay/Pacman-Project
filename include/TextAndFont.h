#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>


class TextAndFont
{
public:
	TextAndFont();
	~TextAndFont();

	char numToString(int num) const;
	void setLives(int num);
	void setScore(int num);
	void setTime();
	int getTime();
	void resetTime();
	void draw(sf::RenderWindow& window) const;
	void increaseTime();

private:
	sf::Text m_lives;
	sf::Text m_clock;
	sf::Text m_score;
	sf::Text m_lives_num;
	sf::Text m_score_num;

	sf::Clock m_clock_num;
	bool m_resetTime = false;
	bool m_increaseTime = false;
	
};
