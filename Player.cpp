#include "Player.h"

Player::Player()
{

}

Player::Player(sf::Vector2f initP)
{
    arSetPosition(initP);
}

float Player::arGetStamina()
{
    return m_stamina;
}
