#include "include.h"
#include "input.h"
#include "render.h"

int main()
{
    std::cout << "Hello Again!" << std::endl;

    //Create window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Cliffeside");
    window.setFramerateLimit(60);


    RenderSys renderer;

    sf::Clock clock;

    //Initialize rendering
    renderer.arInit();

    while(window.isOpen())
    {
        sf::Event windowEvents;

        while(window.pollEvent(windowEvents))
        {
            if (windowEvents.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        //Retrieve delta time
        //Update components
        sf::Time elapsed = clock.restart();
        float delta = elapsed.asSeconds();

        //Update and render window
        renderer.arUpdate(delta);


        renderer.arRender(window);
    }



    return 0;
}
