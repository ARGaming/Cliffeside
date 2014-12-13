#ifndef ENTITY_H
#define ENTITY_H

#include<SFML/Graphics.hpp>
#include <string>

class Entity : sf::Transformable
{
public:
    Entity();
    Entity(sf::Vector2f);

    void freeMove(sf::Vector2f);
    void lockMove(sf::Vector2f);

    sf::Vector2f arGetPosition();
    sf::Vector2f arGetSize();
    sf::Texture arGetTexture();
    sf::Sprite arGetSprite();

    int arGetHealth();

    bool arGetAlive();

    float arGetSpeed();
    float arGetRotation();
    float arGetAngle();

    void arSetSpeed(int speed);
    void arSetPosition(sf::Vector2f);
    void arSetAngle(float angle);
    void arSetHealth(int);
    void arSetAlive(bool);
    void arSetSize(sf::Vector2f);
    void arSetTexture(std::string);
    void arRotate(float);
    void arMovePlayer(float, float);

protected:
    sf::Vector2f m_pos;
    sf::Vector2f m_vSize;
    sf::Sprite m_sprite;
    sf::Texture m_texture;

    int m_health;

    bool m_alive;

    float m_speed;
    float m_angle;
};



#endif // CREATURE_H


