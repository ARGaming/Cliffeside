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
const double PI = 4.0*atan(1.0);

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

    /*Game Objects*/
    //Weapon Arc
    Arc arc(0.001f, 135, 60);
    arc.arSetPosition(sf::Vector2f(500, 500));

    //Stamina bars
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


    /*Game Loop*/
    while(gWind.isOpen())
    {
        gWind.clear();
        loopTime.restart();
        gWind.draw(bg);
        gWind.draw(player.arGetSprite());
        gWind.draw(arc);

        if(gWind.pollEvent(eventH))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(gWind);

           //the angle of ration is the atan2 of the Vector(Distance between mouse and sprite) * (180/PI) to turn it into degrees (atan2 returns radians)
           float angle = std::atan2(mousePos.y - player.arGetPosition().y, mousePos.x - player.arGetPosition().x) * (180/PI);
           player.arRotate(angle);
           player.arSetViewDir(sf::Vector2f(mousePos.x - player.arGetPosition().x, mousePos.y - player.arGetPosition().y));

           std::cout << "\nView Dir:  X=" << player.arGetViewDir().x << " Y=" << player.arGetViewDir().y;

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
                arc.arStartSwing(90);

                if (eventH.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2f mousePos;
                    mousePos.x = sf::Mouse::getPosition(gWind).x;
                    mousePos.y = sf::Mouse::getPosition(gWind).y;

                    /*Quadrant 2*/
                    if (mousePos.x < 640)
                    {
                        if (mousePos.y < 360)
                        {
                            player.arRotate(-135);
                        }
                        else
                        {
                            player.arRotate(135);
                        }
                    }
                    else
                    {
                        if (mousePos.y < 360)
                        {
                            player.arRotate(-45);
                        }
                        else
                        {
                            player.arRotate(45);
                        }
                    }
                }

            }
            else if (eventH.type == sf::Event::MouseButtonPressed)
            {
                if (eventH.mouseButton.button == sf::Mouse::Left)
                {
                    arc.arStartSwing(90);
                }

                if (eventH.mouseButton.button == sf::Mouse::Right)
                {

                }
            }
        }
        if (eventH.type == sf::Event::Closed)
        {
            break;
        }

        deltaTime += loopTime.getElapsedTime();
        arc.arUpdate(deltaTime.asSeconds());

        std::vector<sf::Vector2f> arcColPoints = arc.arGetCollisionPoints();

        for (auto it = arcColPoints.begin(); it != arcColPoints.end(); ++it)
        {
            sf::CircleShape cs(2);
            cs.setPosition(*it);
            gWind.draw(cs);
        }

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
