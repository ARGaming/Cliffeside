#include "entity.h"

bool Entity::checkAlive()
{
    return isAlive;
}

void Entity::setPosition(sf::Vector2f newPos)
{
    position.x = newPos.x;
    position.y = newPos.y;
}

sf::Vector2f Entity::getPosition()
{
    return position;
}

void Entity::setMotion(sf::Vector2f newMot)
{
    motion.x = newMot.x;
    motion.y = newMot.y;
}

sf::Vector2f Entity::getMotion()
{
    return motion;
}

void Entity::updatePosition(float delta)
{
    position.x = motion.x * delta * speed;
    position.y = motion.y * delta * speed;
}
