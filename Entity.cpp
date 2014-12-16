#include "Entity.h"
#include "Math.h"
#include <cmath>
#include <iostream>

using namespace arMath;

Entity::Entity()
{
    m_pos.x = 0;
    m_pos.y = 0;
    m_angle = 0;
    m_speed = 5.0;
}

Entity::Entity(sf::Vector2f initP)
{
    m_pos.x = initP.x;
    m_pos.y = initP.y;

    m_sprite.setPosition(m_pos);
    m_sprite.setOrigin(30, 25);
}

void Entity::lockMove(sf::Vector2f movVector)
{
    m_pos.x += movVector.x;
    m_pos.y += movVector.y;
}

void Entity::freeMove(sf::Vector2f movVector)
{
    m_pos.x += movVector.x;
    m_pos.y += movVector.y;

    /*
    movVector =  Math::normalize(movVector);

    m_angle.x = movVector.x;
    m_angle.y = movVector.y;
    */
}

sf::Vector2f Entity::arGetPosition()
{
    return m_pos;
}
float Entity::arGetAngle()
{
    return m_angle;
}

int Entity::arGetHealth()
{
    return m_health;
}

bool Entity::arGetAlive()
{
    return m_alive;
}

float Entity::arGetSpeed()
{
    return m_speed;
}

sf::Vector2f Entity::arGetSize()
{
    return m_vSize;
}

sf::Sprite Entity::arGetSprite()
{
    return m_sprite;
}

sf::Texture Entity::arGetTexture()
{
    return m_texture;
}

float Entity::arGetRotation()
{
    return m_angle;
}


void Entity::arSetPosition(sf::Vector2f posDelta)
{
    m_pos.x = posDelta.x;
    m_pos.y = posDelta.y;
    m_sprite.setPosition(posDelta);
}

void Entity::arSetAngle(float angle)
{
    m_angle = angle;
}

void Entity::arSetHealth(int newHealth)
{
    m_health += newHealth;
}

void Entity::arSetAlive(bool isAlive)
{
    m_alive = isAlive;
}

void Entity::arSetSize(sf::Vector2f newSize)
{
    m_vSize = newSize;
    m_sprite.setOrigin(m_vSize.x / 2, m_vSize.y / 2);
}

void Entity::arSetSpeed(int newSpeed)
{
    m_speed = newSpeed;
}

void Entity::arSetTexture(std::string filename)
{
    m_texture.loadFromFile(filename);
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
}

void Entity::arRotate(float angle)
{
    std::cout << angle << " ";
    m_sprite.setRotation(angle);
    m_angle = angle;
    std::cout << m_angle << std::endl;
}

void Entity::arMovePlayer(float dx, float dy)
{
    m_sprite.move(dx, dy);
}
