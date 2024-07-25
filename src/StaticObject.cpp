#include "StaticObject.h"



StaticObject::StaticObject() : m_isDisposed(false) {}  

StaticObject::StaticObject(const sf::Vector2f& pos, const sf::Texture& tex) :GameObject(pos, tex) { m_isDisposed = false; }

StaticObject::~StaticObject() {}

bool StaticObject::get_is_disposed() const 
{
	return m_isDisposed;
}

void StaticObject::set_is_disposed()
{
	m_isDisposed = true;
}
