#ifndef RENDER_H
#define RENDER_H

#include "include.h"
#include "World.h"
#include "player.h"

class RenderSys
{
private:
    World* world;
    Player* player;

public:
    std::vector<Entity*> GameEntities;

    void arRender(sf::RenderWindow& window);
    void arUpdate(float delta);
    void arInit();

};

#endif // RENDER_H
