#ifndef RENDER_H
#define RENDER_H

#include "include.h"
#include "World.h"
class RenderSys
{
private:
    World* world;

public:
    void arRender(sf::RenderWindow& window);
    void arUpdate(float delta);
    void arInit();

};

#endif // RENDER_H
