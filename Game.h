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
#include "WorldRenderer.h"


class Game
{
public:
    Game();
    ~Game();
    void arRun();

    const float BAR_HEIGHT = 300;
    const float FRAMETIME = 16.667;
    float angle;

    sf::Event eventH;
    sf::Clock gameTime;
    sf::Clock loopTime;
    sf::Time deltaTime;
    sf::RenderWindow gWind;
    sf::RenderStates states;

    bool gameRunning;

    WorldRenderer* world;
    Player* player;
    Bar* staminaBar;
    Bar* manaBar;

};




#endif // GAME_H_INCLUDED
