#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H


#include "include.h"
#include "component.h"

class ComponentSys;

class SystemManager
{
private:
    std::vector<ComponentSys*> m_GameSystems;

public:
    SystemManager();
    ~SystemManager();

    void SysInit();
    void SysUpdate(float delta);
    void SysRender(sf::RenderWindow& window);

    void AddGameSystem(ComponentSys* system);
};



#endif // SYSTEMMANAGER_H
