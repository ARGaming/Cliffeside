#include "render.h"
#include "player.h"

void RenderSys::arInit()
{
    world = new World();
    world->arInitWorld();


    //Add the player manually since there is no way of calling the addGameObject() function before defining the player object
    Player* player = new Player();
    gameObjectsManager.addGameObject(player);

    //Initialize Entities
    for (Entity* entity : gameObjectsManager.getGameObjects())
    {
        entity->init();
    }

}

void RenderSys::arUpdate(float delta)
{
    world->arUpdateWorld(delta);

    //Update Entities
    for (Entity* entity : gameObjectsManager.getGameObjects())
    {
        //Check if the entity is alive, if it is update if not remove it from the vector
        if (entity->checkAlive())
        {
            entity->update(delta);
        }
        else
        {
            //Retrieve the index of the entity
            int entityIndex = std::find(gameObjectsManager.getGameObjects().begin(), gameObjectsManager.getGameObjects().end(), entity) - gameObjectsManager.getGameObjects().begin();
            //Remove the entity
            gameObjectsManager.getGameObjects().erase(gameObjectsManager.getGameObjects().begin() + entityIndex);
        }
    }
}

void RenderSys::arRender(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    world->arRenderWorld(window);

    //Render Entities
    for (Entity* entity : gameObjectsManager.getGameObjects())
    {
        //Check if the entity is alive, if it is render if not remove it from the vector
        if (entity->checkAlive())
        {
            entity->render(window);
        }
        else
        {
            //Retrieve the index of the entity
            //int entityIndex = std::find(gameObjectsManager.getGameObjects().begin(), gameObjectsManager.getGameObjects().end(), entity) - gameObjectsManager.getGameObjects().begin();
            //Remove the entity
            //gameObjectsManager.getGameObjects().erase(gameObjectsManager.getGameObjects().begin() + entityIndex);
        }
    }

    window.display();
}
