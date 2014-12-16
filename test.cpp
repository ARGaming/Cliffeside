#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include "Math.h"
#include "Player.h"
#include "Arc.h"
#include "Entity.h"

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

    //Stamina bars
    sf::RectangleShape sideBar[2];

    sideBar[0].setSize(sf::Vector2f(20,BAR_HEIGHT));
    sideBar[1].setSize(sf::Vector2f(20,BAR_HEIGHT));

    sideBar[0].setPosition(40,50);
    sideBar[1].setPosition(40,50 + 20);

    sideBar[0].setRotation(270);
    sideBar[1].setRotation(270);

    sideBar[0].setFillColor(sf::Color(255,255,0,120));
    sideBar[0].setOutlineColor(sf::Color(255,255,99,120));
    sideBar[0].setOutlineThickness(2);
    sideBar[1].setFillColor(sf::Color(0,0,255,120));
    sideBar[1].setOutlineColor(sf::Color(99,99,255,120));
    sideBar[1].setOutlineThickness(2);

    float percental[2];
    percental[0] = .001;
    percental[1] = .001;

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
            if(percental[0] >= 1)
            {
            }
            else if(percental[0] + (.01667/4.5) >= 1)
            {
                percental[0] = 1;
            }
            else
            {
                percental[0] += .01667/4.5;
            }
            if(percental[1] >= 1)
            {
            }
            else if(percental[1] + (.01667/36) >= 1)
            {
                percental[1] = 1;
            }
            else
            {
                percental[1] += (.01667/36);
            }

            player.arUpdate(angle);

            sideBar[0].setScale(sf::Vector2f(1,percental[0]));
            sideBar[1].setScale(sf::Vector2f(1,percental[1]));

            deltaTime -= sf::milliseconds(FRAMETIME);
        }

        //Draw
        gWind.clear();
        gWind.draw(bg);
        player.draw(gWind);

        gWind.draw(sideBar[0]);
        gWind.draw(sideBar[1]);

        gWind.display();

        //Update delta time
        deltaTime += loopTime.restart();
    }
    return 0;
}
