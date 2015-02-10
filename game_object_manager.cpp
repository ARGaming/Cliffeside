#include "game_object_manager.h"

void GameObjectManager::addGameObject(Entity* entity)
{
    gameObjects.push_back(entity);
}

std::vector<Entity*> GameObjectManager::getGameObjects()
{
    return gameObjects;
}
