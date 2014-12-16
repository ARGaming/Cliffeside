#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include "Math.h"
#include "Player.h"
#include "Arc.h"
#include "Entity.h"
#include "Bar.h"

using namespace arMath;

const float BAR_HEIGHT = 300;
const float FRAMETIME = 16.667;


int main()
{
    sf::RenderWindow gWind(sf::VideoMode(1280,720),"Grid Test");
    sf::Event eventH;
    sf::Clock gameTime;
    sf::Clock loopTime;
    sf::Time deltaTime;

    /*Background*/
    sf::RectangleShape bg;
    bg.setFillColor(sf::Color::Black);
    bg.setSize(sf::Vector2f(1280,720));

    /*Game Entities*/
    //Player
    Player player(sf::Vector2f(1280 / 2, 720 / 2));
    player.arSetTexture("player.png");
    player.arSetSize(sf::Vector2f(50.0, 50.0));
    float angle = 0.0;

    //Bars
    Bar staminaBar(sf::Vector2f(BAR_HEIGHT, 20), sf::Color(255, 255, 0, 200));
    Bar manaBar(sf::Vector2f(BAR_HEIGHT, 20), sf::Color(0, 55, 255, 200));

    staminaBar.arSetPosition(sf::Vector2f(20, 20));
    manaBar.arSetPosition(sf::Vector2f(20, 50));

    /*Game Loop*/
    while(gWind.isOpen())
    {
        //Handle events
        while (gWind.pollEvent(eventH))
        {
            player.arHandleEvent(eventH);

            if(eventH.type == sf::Event::KeyPressed)
            {
                if(eventH.key.code == sf::Keyboard::Escape)
                {
                    gWind.close();
                    break;
                }
            }

            //the angle of ration is the atan2 of the Vector(Distance between mouse and sprite) * (180/PI) to turn it into degrees (atan2 returns radians)
            sf::Vector2i mousePos = sf::Mouse::getPosition(gWind);
            angle = std::atan2(mousePos.y - player.arGetPosition().y, mousePos.x - player.arGetPosition().x) * (180/PI);

            if (eventH.type == sf::Event::Closed)
            {
                gWind.close();
                break;
            }
        }

        //Update
        while (deltaTime.asMilliseconds() > FRAMETIME)
        {
            player.arUpdate(angle);
            staminaBar.arFill(0.01677f); //1 second at 60 fps
            manaBar.arFill(0.01677f/4); //4 seconds at 60 fps

            deltaTime -= sf::milliseconds(FRAMETIME);
        }

        //Draw
        gWind.clear();
        gWind.draw(bg);
        player.draw(gWind);

        gWind.draw(staminaBar);
        gWind.draw(manaBar);

        gWind.display();

        //Update delta time
        deltaTime += loopTime.restart();
    }
    return 0;
}
