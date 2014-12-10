#include "Arc.h"

#include <iostream>

Arc::Arc(float speed, float range, float length)
    : m_speed(speed)
    , m_range(range)
    , m_collider(sf::Vector2f(length, 1))
    , m_swinging(false)
    , m_swingPercentage(0) //unnecessary?
    , m_beginSwingAngle(0)
{
    m_collider.setFillColor(sf::Color::Red);
}


void Arc::update(float dt)
{
    if (m_swinging)
    {
        if (m_swingPercentage >= 0.999f)
        {
            m_swinging = false;
            m_swingPercentage = 0;
        }
        else
        {
            m_collider.rotate(m_range * m_speed);
            m_swingPercentage = m_collider.getRotation() / (m_beginSwingAngle + m_range);
            std::cout << m_swingPercentage << "\n";
        }
    }
}

void Arc::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_collider, states);
}

void Arc::startSwing(float angle)
{
    m_swinging = true;
    m_beginSwingAngle = angle;
    m_collider.setRotation(angle);
}

void Arc::setPosition(const sf::Vector2f& pos)
{
    m_collider.setPosition(pos);
}

sf::FloatRect Arc::getCollider()
{
    return sf::FloatRect(m_collider.getPosition(), m_collider.getSize());
}
