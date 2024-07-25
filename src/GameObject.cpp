#include "GameObject.h"

GameObject::GameObject()
{
	m_char = ' ';
}

GameObject::GameObject(const sf::Vector2f& pos, const sf::Texture& tex) : GameObject(tex) // reuse
{
	setPosition(pos);
}

void GameObject::setScale(const sf::Vector2f& scale)
{
	m_sprite.scale(scale);
}

GameObject::GameObject(const sf::Texture& tex) : m_sprite(tex)
{
	m_char = ' ';
}

void GameObject::drawObject(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void GameObject::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}

sf::Vector2f GameObject::getPosition() const
{

	return m_sprite.getPosition();
}

char GameObject::getChar() const
{
	return m_char;
}

sf::FloatRect GameObject::getBounds() const
{
	return m_sprite.getGlobalBounds();
}

void GameObject::handleCollison(GameObject& obj)
{
	obj.handleCollison(*this);
}

