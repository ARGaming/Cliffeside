#ifndef ENTITY_H
#define ENTITY_H

#include<SFML/Graphics.hpp>
#include <string>
#include "../Components/PhysicsBody.h"

class Entity
{
public:
    Entity();
    Entity(sf::Vector2f);

    void freeMove(sf::Vector2f);
    void lockMove(sf::Vector2f);

    sf::Vector2f arGetPosition();
    sf::Vector2f arGetSize();
    sf::Texture arGetTexture(bool);
    sf::Sprite arGetSprite();

    int arGetHealth();

    bool arGetAlive();

    float arGetSpeed();
    float arGetRotation();
    float arGetAngle();

    void arSetSpeed(int speed);
    void arSetPosition(sf::Vector2f posDelta);
    void arSetAngle(float angle);
    void arSetHealth(int newHealth);
    void arSetAlive(bool);
    void arSetSize(sf::Vector2f);
    void arSetTexture(std::string filename, bool isFront);
    void arSetScale(float x, float y);
    void arRotate(float angle);
    void arMovePlayer(float dx, float dy);


    virtual void draw(sf::RenderTarget& target) = 0;

    int arGetRenderLayer();

    enum LayerType {EntityRenderLayer = 1, BackgroundRenderLayer = 0, ForegroundRenderLayer = 2};

    std::vector<PhysicsBody*> arGetBodyParts();


protected:
    sf::Vector2f m_pos;
    sf::Vector2f m_vSize;
    sf::Sprite m_sprite;
    sf::Texture m_texturef;
    sf::Texture m_textureb;

    int m_health;

    bool m_alive;
    bool isFront;

    float m_speed;
    float m_angle;
    int m_renderLayer;

    PhysicsBody* physicsBody;

    std::vector<PhysicsBody*> bound_body_parts;

};



#endif // CREATURE_H


