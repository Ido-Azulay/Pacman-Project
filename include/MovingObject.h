#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
    using MovingVector = std::vector<std::unique_ptr <MovingObject>>;
    using StaticVector = std::vector<std::unique_ptr <StaticObject>>;

    MovingObject();
    MovingObject(const sf::Texture& tex);
    MovingObject(const sf::Vector2f& pos, const sf::Texture& tex);


    virtual ~MovingObject() = default;

    virtual void move(sf::Time delta , MovingVector& , StaticVector&) = 0;

    virtual void updateDirection(sf::Vector2f& obj , int num) = 0; 

    void setOriginalPosition(sf::Vector2f pos);
    sf::Vector2f getOriginalPosition();

    virtual void setFreeze() = 0;
    virtual void stopFreeze() = 0;
    virtual void setSuper() = 0;
    virtual void stopSuper() = 0;
  

    enum class Direction
    {
        Up,
        Down,
        Right,
        Left,
        Stay,
        Max,
    };

protected:
 
    Direction m_direction = Direction::Stay;
    Direction opposite(Direction dir);
    sf::Vector2f directionToVector(Direction dir);


    sf::Vector2f m_stepSize;
    sf::Vector2f m_original_position;
    bool m_freeze = false;
private:

};



