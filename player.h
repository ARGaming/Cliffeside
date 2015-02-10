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
    Player();

    void setShoot(bool shooting);
    bool isShooting();

    void init() override;
    void render(sf::RenderWindow&) override;
    void update(float) override;

};

#endif // PLAYER_H

