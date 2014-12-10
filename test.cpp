#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include "Math.h"
#include "Player.h"
#include "Arc.h"

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


    sf::RectangleShape bg;
    bg.setFillColor(sf::Color::Black);
    bg.setSize(sf::Vector2f(1280,720));

    Player player(sf::Vector2f(1280 / 2, 720 / 2));
    player.arSetTexture("testTrig.png");

    Arc arc(0.001f, 135, 60);
    arc.setPosition(sf::Vector2f(500, 500));

    sf::RectangleShape sideBar[2];

    sideBar[0].setSize(sf::Vector2f(20,BAR_HEIGHT));
    sideBar[1].setSize(sf::Vector2f(20,BAR_HEIGHT));

    sideBar[0].setPosition(200,600);
    sideBar[1].setPosition(200,600 + 20);

    sideBar[0].setRotation(270);
    sideBar[1].setRotation(270);

    sideBar[0].setFillColor(sf::Color::Yellow);
    sideBar[0].setOutlineColor(sf::Color::White);
    sideBar[0].setOutlineThickness(2);
    sideBar[1].setFillColor(sf::Color::Blue);
    sideBar[1].setOutlineColor(sf::Color::White);
    sideBar[1].setOutlineThickness(2);


    float percental[2];
    percental[0] = .001;
    percental[1] = .001;


    while(gWind.isOpen())
    {
        gWind.clear();
        loopTime.restart();
        gWind.draw(bg);
        gWind.draw(arc);

        if(gWind.pollEvent(eventH))
        {
            if(eventH.type == sf::Event::KeyPressed)
            {

                if(eventH.key.code == sf::Keyboard::Escape)
                {
                    break;
                }


                if (eventH.key.code == sf::Keyboard::A)
                {
                   player.arMovePlayer(-10, 0);
                }

                if (eventH.key.code == sf::Keyboard::S)
                {
                    player.arMovePlayer(0, 10);
                }

                if (eventH.key.code == sf::Keyboard::W)
                {
                    player.arMovePlayer(0, -10);
                }

                if (eventH.key.code == sf::Keyboard::D)
                {
                    player.arMovePlayer(10, 0);
                }

                if (eventH.key.code == sf::Keyboard::F)
                {
                    player.arRotate(0);

                }

                if (eventH.key.code == sf::Keyboard::C)
                {
                    player.arRotate(180);
                }

            }
            else if (eventH.type == sf::Event::MouseButtonPressed)
            {
                arc.startSwing(90);

                if (eventH.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos;
                    mousePos.x = sf::Mouse::getPosition().x;
                    mousePos.y = sf::Mouse::getPosition().y;

                    /*Quadrant 2*/
                    if (mousePos.x >= 0 && mousePos.x < 640)
                    {
                        if (mousePos.y >= 0 && mousePos.y < 360)
                        {
                            player.arRotate(45);
                        }

                    }

                    /*Quadrant 1*/
                    if (mousePos.x >= 640 && mousePos.x <= 1280)
                    {
                        if (mousePos.y < 360 && mousePos.y >= 0)
                        {
                            player.arRotate(135);
                        }
                    }

                    /*Quadrant 3*/
                    if (mousePos.x >= 0 && mousePos.x < 640)
                    {
                        if (mousePos.y >= 360 && mousePos.y <= 720)
                        {
                            player.arRotate(-45);
                        }

                    }

                    /*Quadrant 4*/
                    if (mousePos.x >= 640 && mousePos.x <= 1280)
                    {
                        if (mousePos.y >= 360 && mousePos.y <= 720)
                        {
                            player.arRotate(-135);
                        }

                    }
                }
            }

        }

        if (eventH.type == sf::Event::Closed)
        {

            break;
        }

        gWind.draw(player.arGetSprite());

        deltaTime += loopTime.getElapsedTime();
        arc.update(deltaTime.asSeconds());
        if(deltaTime.asMilliseconds() > FRAMETIME)
        {
            if(percental[0] >= 1)
            {
            }
            else if(percental[0] + .01667 >= 1)
            {
                percental[0] = 1;
            }
            else
            {
                percental[0] += .01667;
            }
            if(percental[1] >= 1)
            {
            }
            else if(percental[1] + (.01667/2) >= 1)
            {
                percental[1] = 1;
            }
            else
            {
                percental[1] += (.01667/2);
            }
            deltaTime -= sf::milliseconds(FRAMETIME);
            sideBar[0].setScale(sf::Vector2f(1,percental[0]));
            sideBar[1].setScale(sf::Vector2f(1,percental[1]));

        }


        gWind.draw(sideBar[0]);
        gWind.draw(sideBar[1]);

        gWind.display();
    }
    return 0;
}
