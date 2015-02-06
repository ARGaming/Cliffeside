#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "include.h"

class World
{
private:
    sf::Texture backgroundTex;
    sf::Sprite background;

public:
    void arInitWorld();
    void arUpdateWorld(float delta);
    void arRenderWorld(sf::RenderWindow& window);
};



#endif // WORLD_H_INCLUDED
