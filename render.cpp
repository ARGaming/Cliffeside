#include "render.h"

void RenderSys::arInit()
{
    world = new World();
    world->arInitWorld();

    //Create the player
    player = new Player("player", sf::Vector2f(400, 400));

}

void RenderSys::arUpdate(float delta)
{
    world->arUpdateWorld(delta);
    //entity list check?
    player->update(delta);
}

void RenderSys::arRender(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    world->arRenderWorld(window);
    player->render(window);

    window.display();
}
