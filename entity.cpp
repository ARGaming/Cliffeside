#include "entity.h"
#include "game_object_manager.h"


bool Entity::checkAlive()
{
    return isAlive;
}

void Entity::setPosition(sf::Vector2f newPos)
{
    position.x = newPos.x;
    position.y = newPos.y;
    entSprite.setPosition(position);
}

sf::Vector2f Entity::getPosition()
{
    return position;
}

void Entity::setMotion(sf::Vector2i newMot)
{
    motion.x = newMot.x;
    motion.y = newMot.y;
}

sf::Vector2i Entity::getMotion()
{
    return motion;
}

void Entity::updatePosition(float delta)
{
    position.x += motion.x * delta * speed;
    position.y += motion.y * delta * speed;
    entSprite.setPosition(position);
}

void Entity::setID(std::string new_id)
{
    id = new_id;
}

std::string Entity::getID()
{
    return id;
}

void Entity::setTexture(std::string frontFilename, std::string backFilename)
{
    frontTexture.loadFromFile(frontFilename);
    frontTexture.setSmooth(true);
    entSprite.setTexture(frontTexture);

    backTexture.loadFromFile(backFilename);

    viewDir.x = 1;
    viewDir.y = 0;

}

sf::Sprite Entity::getSprite()
{
    return entSprite;
}

void Entity::setSpeed(int new_speed)
{
    speed = new_speed;
}

void Entity::flipTexture(bool isFront)
{
    if (isFront)
    {
        entSprite.setTexture(frontTexture);
        viewDir.x = 1;
        viewDir.y = 0;
    }

    if (!isFront)
    {
        entSprite.setTexture(backTexture);
        viewDir.x = -1;
        viewDir.y = 0;
    }
}

sf::Vector2i Entity::getViewDir()
{
    return viewDir;
}

void Entity::setAlive(bool new_alive)
{
    isAlive = new_alive;
}


