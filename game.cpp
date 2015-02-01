#include "include.h"
#include "input.h"
#include "SystemManager.h"

int main()
{
    std::cout << "Hello Again!" << std::endl;

    sf::VideoMode screen();
    //Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cliffeside");
    window.setFramerateLimit(60);

    //Input handle for window
    InputSys* inputHandler = new InputSys();

    //System manager that will handle the update and render of each subsystem of the game
    SystemManager* systemManager = new SystemManager();


    //Initialize components
    systemManager->SysInit();

    sf::Clock clock;

    while(window.isOpen())
    {
        sf::Event windowEvents;

        while(window.pollEvent(windowEvents))
        {
            inputHandler->arHandleWindowEvents(window, windowEvents);
        }

        //Update components
        sf::Time elapsed = clock.restart();
        float delta = elapsed.asSeconds();
        systemManager->SysUpdate(delta);

        //Render Components
        systemManager->SysRender(window);

    }

    delete inputHandler;
    delete systemManager;

    return 0;
}
