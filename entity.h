#ifndef ENTITY_H
#define ENTITY_H

#include "include.h"

class Entity
{
private:
    bool isAlive;
    sf::Vector2f position;
    sf::Vector2i motion;
    int speed;

    sf::Vector2i viewDir;

    float health;

    std::string id;

    sf::Sprite entSprite;
    //Front texture
    sf::Texture frontTexture;
    sf::Texture backTexture;


public:


    bool checkAlive();
    void setAlive(bool);

    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition();

    void setSpeed(int);

    void setMotion(sf::Vector2i);
    sf::Vector2i getMotion();

    void updatePosition(float);

    void setID(std::string);
    std::string getID();

    void setTexture(std::string, std::string);
    sf::Sprite getSprite();

    void flipTexture(bool);

    sf::Vector2i getViewDir();

    virtual void init() = 0;
    virtual void render(sf::RenderWindow&) = 0;
    virtual void update(float) = 0;

};

#endif // ENTITY_H

