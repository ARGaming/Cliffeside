#ifndef PLAYER_H
#define PLAYER_H

#include "include.h"
#include "entity.h"

class Player : public Entity
{
private:
    bool shoot;

    void handleInput();

public:
    Player(std::string, sf::Vector2f);
    ~Player();

    void setShoot(bool shooting);
    bool isShooting();

    void render(sf::RenderWindow&) override;
    void update(float) override;

};

#endif // PLAYER_H

