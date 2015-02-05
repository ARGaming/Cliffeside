#ifndef ENTITY_H
#define ENTITY_H

#include "include.h"

class Entity
{
private:
    bool isAlive;
    sf::Vector2f position;
    sf::Vector2f motion;
    int speed;

public:
    bool checkAlive();

    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition();

    void setMotion(sf::Vector2f);
    sf::Vector2f getMotion();

    void updatePosition(float);
};

#endif // ENTITY_H

