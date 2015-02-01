#include "SystemManager.h"
#include "render.h"


SystemManager::SystemManager()
{
}

SystemManager::~SystemManager()
{
    m_GameSystems.clear();
}

void SystemManager::SysInit()
{
    RenderSys* renderSystem = new RenderSys();
    m_GameSystems.push_back(renderSystem);
}

void SystemManager::AddGameSystem(ComponentSys* system)
{
    m_GameSystems.push_back(system);
}

void SystemManager::SysUpdate(float delta)
{
    for (ComponentSys* system : m_GameSystems)
    {
        system->arUpdate(delta);
    }
}

void SystemManager::SysRender(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    for (ComponentSys* system : m_GameSystems)
    {
        system->arRender(window);
    }

    window.display();
}
