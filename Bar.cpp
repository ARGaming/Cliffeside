#include "Bar.h"

#include <cmath>
#include <iostream>

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
void Bar::arUpdate(Player* player, std::string type)
{
    if (type.compare("mana") == 0)
    {
        m_shape.setPosition(player->arGetPosition().x - 280, player->arGetPosition().y - 180);
    }
    else if (type.compare("stamina") == 0)
    {
        m_shape.setPosition(player->arGetPosition().x - 280, player->arGetPosition().y - 150);
    }
    else {

    }
}

void Bar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
}
