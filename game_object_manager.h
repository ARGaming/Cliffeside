#ifndef GAME_OBJECT_MANAGER_H_INCLUDED
#define GAME_OBJECT_MANAGER_H_INCLUDED

#include "entity.h"
#include "include.h"

class GameObjectManager
{
private:
    std::vector<Entity*> gameObjects;


public:
    void addGameObject(Entity*);
    std::vector<Entity*> getGameObjects();

};



#endif // GAME_OBJECT_MANAGER_H_INCLUDED
