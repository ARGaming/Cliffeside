#include "Game.h"

using namespace arMath;

Game::Game()
{
    std::cout << "Engine started...\n";

    gWind.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cliffeside");
    cameraView.setCenter(300, 200);
    cameraView.setSize(600, 400);
    gWind.setView(cameraView);

    gameRunning = true;

    std::cout << "Game started...\n";
    angle = 0.0;

    player = new Player(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), sf::Vector2f(100.0, 100.0));
    staminaBar = new Bar(sf::Vector2f(BAR_HEIGHT, 20), sf::Color(255, 255, 0, 200));
    manaBar = new Bar(sf::Vector2f(BAR_HEIGHT, 20), sf::Color(0, 55, 255, 200));

    //Background
    bgtxtr.loadFromFile("badBG.png");
    bgtxtr.setSmooth(true);
    bg.setTexture(bgtxtr);
    bg.setScale(1.6, 1.6);

    staminaBar->arSetPosition(sf::Vector2f(20, 20));
    manaBar->arSetPosition(sf::Vector2f(20, 50));
}

Game::~Game()
{
    player = nullptr;
    staminaBar = nullptr;
    manaBar = nullptr;
}

void Game::arRun()
{
    /*Game Loop*/
    while(gWind.isOpen())
    {
        if (gameRunning == false)
        {
            break;
        }

        //Handle events
        while (gWind.pollEvent(eventH))
        {
            player->arHandleEvent(eventH);

            if(eventH.type == sf::Event::KeyPressed)
            {
                if(eventH.key.code == sf::Keyboard::Escape)
                {
                    gWind.close();
                    gameRunning = false;
                    break;
                }
            }

            if (eventH.type == sf::Event::Closed)
            {
                gWind.close();
                gameRunning = false;
                break;
            }
        }

        //Update
        while (deltaTime.asMilliseconds() > FRAMETIME)
        {
            //the angle of ration is the atan2 of the Vector(Distance between mouse and sprite) * (180/PI) to turn it into degrees (atan2 returns radians)
            sf::Vector2i mousePos = sf::Mouse::getPosition(gWind);
            angle = std::atan2(mousePos.y - player->arGetPosition().y, mousePos.x - player->arGetPosition().x) * (180/PI);

            player->arUpdate(angle, cameraView);
            gWind.setView(cameraView);

            staminaBar->arFill(0.01677f); //1 second at 60 fps
            manaBar->arFill(0.01677f/4); //4 seconds at 60 fps

            deltaTime -= sf::milliseconds(FRAMETIME);
        }

        staminaBar->arUpdate(player, "stamina");
        manaBar->arUpdate(player, "mana");


        //Draw
        gWind.clear();

        gWind.draw(bg);
        player->draw(gWind);
        staminaBar->draw(gWind, states);
        manaBar->draw(gWind, states);

        gWind.display();

        //Update delta time
        deltaTime += loopTime.restart();
    }
}



