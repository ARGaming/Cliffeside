#include "Player.h"

Player::Player()
{
}

Player::Player(sf::Vector2f initP)
{
    arSetPosition(initP);
    m_viewDir.x = 1;
    m_viewDir.y = 0;

}

float Player::arGetStamina()
{
    return m_stamina;
}

sf::Vector2f Player::arGetBodyCenter()
{
    sf::Vector2f bodyCenter;

    bodyCenter.x = arGetSize().x/2.0;
    bodyCenter.y = arGetSize().y/2.0;

    return bodyCenter;
}

sf::Vector2f Player::arGetViewDir()
{
    return m_viewDir;
}

void Player::arSetViewDir(sf::Vector2f dir)
{
    m_viewDir = dir;
}
