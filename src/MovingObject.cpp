#include "MovingObject.h"

MovingObject::MovingObject()
{
}

MovingObject::MovingObject(const sf::Texture& tex): GameObject(tex)
{
}

MovingObject::MovingObject(const sf::Vector2f& pos, const sf::Texture &tex) :  GameObject(pos,tex)
{
}

void MovingObject::setOriginalPosition(sf::Vector2f pos)
{
    m_original_position = pos;
}

sf::Vector2f MovingObject::getOriginalPosition()
{
    return m_original_position;
}

MovingObject::Direction MovingObject::opposite(Direction dir)
{
    switch (dir)
    {
    case Direction::Up:
        return Direction::Down;
    case Direction::Down:
        return Direction::Up;
    case Direction::Right:
        return Direction::Left;
    case Direction::Left:
        return Direction::Right;
    default:
        return Direction::Stay;
    }
}

sf::Vector2f MovingObject::directionToVector(Direction dir)
{
    switch (dir)
    {
    case Direction::Up:
        return { 0, -1 };
    case Direction::Down:
        return { 0, 1 };
    case Direction::Right:
        return { 1, 0 };
    case Direction::Left:
        return { -1, 0 };
    default:
        return { 0, 0 };
    }
}
