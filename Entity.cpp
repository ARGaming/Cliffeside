#include "Entity.h"
#include <cmath>

Entity::Entity()
{
    pos.x = 0;
    pos.y = 0;
    angle.x = 0;
    angle.y = 1;
}

Entity::Entity(sf::Vector2f initP,sf::Vector2f initA)
{
    pos.x = initP.x;
    pos.y = initP.y;
    angle.x = initA.x;
    angle.y = initA.y;
}

void Entity::lockMove(sf::Vector2f movVector)
{
    pos.x += movVector.x;
    pos.y += movVector.y;
}

void Entity::freeMove(sf::Vector2f movVector)
{
    pos.x += movVector.x;
    pos.y += movVector.y;

    float dist = sqrt(movVector.x * movVector.x + movVector.y * movVector.y);

    angle.x = movVector.x / dist;
    angle.y = movVector.y / dist;
}

sf::Vector2f Entity::getPostion()
{
    return pos;
}
sf::Vector2f Entity::getAngle()
{
    return angle;
}

int Entity::getHealth()
{
    return health;
}

bool Entity::getAlive()
{
    return alive;
}

void Entity::setPostion(sf::Vector2f posDelta)
{
    pos.x = posDelta.x;
    pos.y = posDelta.y;
}

void Entity::setAngle(sf::Vector2f angleDelta)
{
    angle.x = angleDelta.x;
    angle.y = angleDelta.y;
}

void Entity::setHealth(int newHealth)
{
    health += newHealth;
}

void Entity::setAlive(bool isAlive)
{
    alive = isAlive;
}
