#include "Bar.h"

#include <cmath>

Bar::Bar(sf::Vector2f size, sf::Color color)
{
    m_shape.setSize(size);
    m_shape.setFillColor(color);
    m_shape.setOutlineColor(sf::Color::Black);
    m_shape.setOutlineThickness(2);
}

void Bar::arSetPosition(sf::Vector2f pos)
{
    m_shape.setPosition(pos);
}

void Bar::arFill(float percentage)
{
    m_percentage += percentage;
    m_percentage = std::min(1.f, m_percentage);
    m_percentage = std::max(0.f, m_percentage);

    m_shape.setScale(m_percentage, 1.f);
}

void Bar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
}
