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

void Player::arUpdate()
{
    sf::Vector2f dir;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir.x -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir.x += 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir.y -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir.y += 1;
    }

    arMovePlayer(dir.x * 10, dir.y * 10);
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
