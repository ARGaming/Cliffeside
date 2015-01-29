#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include "Math.h"
#include "Player.h"
#include "Arc.h"
#include "Entity.h"
#include "Bar.h"



class Game
{
public:
    Game();
    ~Game();
    void arRun();

    const float BAR_HEIGHT = 300;
    const float FRAMETIME = 16.667;
    const float WINDOW_WIDTH = 600;
    const float WINDOW_HEIGHT = 400;
    float angle;

    sf::Event eventH;
    sf::Clock gameTime;
    sf::Clock loopTime;
    sf::Time deltaTime;
    sf::RenderWindow gWind;
    sf::RenderStates states;
    sf::View cameraView;

    bool gameRunning;

    //Entities
    sf::Texture bgtxtr; //Name will change
    sf::Sprite bg;

    Player* player;
    Bar* staminaBar;
    Bar* manaBar;

};




#endif // GAME_H_INCLUDED
