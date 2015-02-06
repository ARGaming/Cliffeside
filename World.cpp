#include "World.h"

void World::arInitWorld()
{
    backgroundTex.loadFromFile("assets/funny_bg.png");
    backgroundTex.setSmooth(true);

    background.setTexture(backgroundTex);
}

void World::arUpdateWorld(float delta)
{

}

void World::arRenderWorld(sf::RenderWindow& window)
{
    window.draw(background);
}
