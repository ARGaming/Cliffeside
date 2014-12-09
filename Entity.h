#ifndef ENTITY_H
#define ENTITY_H

#include<SFML/Graphics.hpp>

class Entity
{
private:
    sf::Vector2f pos;
    sf::Vector2f angle;
    int health;
    bool alive;

public:
    Entity();
    Entity(sf::Vector2f,sf::Vector2f);

    void freeMove(sf::Vector2f);
    void lockMove(sf::Vector2f);

    sf::Vector2f getPostion();
    sf::Vector2f getAngle();
    int getHealth();
    bool getAlive();

    void setPostion(sf::Vector2f);
    void setAngle(sf::Vector2f);
    void setHealth(int);
    void setAlive(bool);
};



#endif // CREATURE_H
