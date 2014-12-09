#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

#include "Entity.h"
#include "Math.h"
#include "Arc.h"

const float BAR_HEIGHT = 300;
const float FRAMETIME = 16.667;

int main()
{
    sf::RenderWindow gWind(sf::VideoMode(1280,720),"Grid Test");
    sf::Event eventH;
    sf::Clock gameTime;
    sf::Clock loopTime;
    sf::Time deltaTime;

    Math arMath;

    sf::Texture testPC;
    testPC.loadFromFile("testSprite.png");
    sf::Sprite bobby(testPC);
    sf::Sprite bobby2(testPC);

    bobby2.setColor(sf::Color::Blue);
    bobby2.setPosition(200,200);
    bobby2.setRotation(-45);

    Entity Bob (sf::Vector2f(2,2),sf::Vector2f(0,1));

    Bob.freeMove(sf::Vector2f(2,1));
    sf::Vector2f pv,av;
    pv = Bob.getPostion();
    av = Bob.getAngle();
    std::cout << pv.x << " " << pv.y << std::endl;
    std::cout << av.x << " " << av.y << std::endl;


    bool isRunning = true;

    sf::RectangleShape bg;
    bg.setFillColor(sf::Color::Green);
    bg.setSize(sf::Vector2f(1280,720));

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

    Arc testArc(0.001f, 270, 70);
    testArc.setPosition(sf::Vector2f(300, 300));

    while(isRunning)
    {
        gWind.clear();
        loopTime.restart();
        gWind.draw(bg);
        gWind.draw(testArc);

        if(gWind.pollEvent(eventH))
        {
            if(eventH.type == sf::Event::KeyPressed)
            {
                if(eventH.key.code == sf::Keyboard::Q)
                {
                    isRunning = false;
                }
                if(eventH.key.code == sf::Keyboard::Escape)
                {
                    isRunning = false;
                }
            }
            else if(eventH.type == sf::Event::MouseButtonPressed)
            {
                if(eventH.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2f mp;
                    mp.x  = sf::Mouse::getPosition(gWind).x;
                    mp.y  = sf::Mouse::getPosition(gWind).y;
                    bobby.setPosition(mp);
                }
                else
                {
                    testArc.startSwing(45);
                }
            }
            else if(eventH.type == sf::Event::MouseMoved and sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                sf::Vector2f mp;
                mp.x  = sf::Mouse::getPosition(gWind).x;
                mp.y  = sf::Mouse::getPosition(gWind).y;
                bobby.setPosition(mp);
            }
            else if(eventH.type == sf::Event::Closed)
            {
                isRunning = false;
            }
        }
        gWind.draw(bobby);
        gWind.draw(bobby2);
        deltaTime += loopTime.getElapsedTime();
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
        testArc.update(deltaTime.asSeconds());


        gWind.draw(sideBar[0]);

        gWind.draw(sideBar[1]);
        gWind.display();
    }
    return 0;
}
