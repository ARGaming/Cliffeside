#include "Arc.h"

#include <iostream>

Arc::Arc(float speed, float range, float length)
    : m_speed(speed)
    , m_range(range)
    , m_ticks(m_range/m_speed)
    , m_tickCount(0)
    , m_collider(sf::Vector2f(length, 1))
    , m_swinging(false)
    , m_beginSwingAngle(0)
{
    m_collider.setFillColor(sf::Color::Red);
}

void Arc::arUpdate()
{
    //Ensure the angle is between 0 and 360
    if (m_swinging)
    {
        if (m_tickCount >= m_ticks)
        {
            m_swinging = false;
            m_tickCount = 0;
        }
        else
        {
            m_collider.rotate(m_speed);
            m_tickCount++;
        }
    }
}

void Arc::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_collider, states);
}

void Arc::arStartSwing(float angle)
{
    m_swinging = true;
    m_beginSwingAngle = angle;
    m_collider.setRotation(angle);
    m_tickCount = 0;
}

void Arc::arSetPosition(const sf::Vector2f& pos)
{
    m_collider.setPosition(pos);
}

float Arc::arGetRange()
{
    return m_range;
}

std::vector<sf::Vector2f> Arc::arGetCollisionPoints()
{
    std::vector<sf::Vector2f> collisionPoints;
    float radians = m_collider.getRotation() * (3.141592653 / 180.f); //move to Math at some point
    sf::Vector2f normAngleVec(std::cos(radians), std::sin(radians)); //turn radians in to a unit vector

    for (int i = 0; i < m_collider.getSize().x; i += 20) //Return positions in steps of 10 pixels
    {
        sf::Vector2f colPos(normAngleVec.x * i, normAngleVec.y * i);
        colPos += m_collider.getPosition();

        collisionPoints.push_back(colPos);
    }

    //collider Size X is the length of the arc
    collisionPoints.push_back(sf::Vector2f(m_collider.getPosition().x + normAngleVec.x * m_collider.getSize().x,
                                           m_collider.getPosition().y + normAngleVec.y * m_collider.getSize().x));

    return collisionPoints;
}
