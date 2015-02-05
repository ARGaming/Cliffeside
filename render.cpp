#include "render.h"

void RenderSys::arInit()
{
    world = new World();
    world->arInitWorld();


}

void RenderSys::arUpdate(float delta)
{
    world->arUpdateWorld(delta);
    //entity list check?
}

void RenderSys::arRender(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    world->arRenderWorld(window);

    window.display();
}
