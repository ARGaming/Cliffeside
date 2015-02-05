#include "include.h"
#include "input.h"
#include "render.h"

int main()
{
    std::cout << "Hello Again!" << std::endl;

    //Create window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Cliffeside");
    window.setFramerateLimit(60);

    //Input handle for window
    InputSys* inputHandler = new InputSys();
    RenderSys* renderer = new RenderSys();

    sf::Clock clock;

    //Initialize rendering
    renderer->arInit();

    while(window.isOpen())
    {
        sf::Event windowEvents;

        while(window.pollEvent(windowEvents))
        {
            inputHandler->arHandleWindowEvents(window, windowEvents);
        }

        //Retrieve delta time
        //Update components
        sf::Time elapsed = clock.restart();
        float delta = elapsed.asSeconds();

        //Update and render window
        renderer->arUpdate(delta);


        renderer->arRender(window);
    }

    delete inputHandler;

    return 0;
}
