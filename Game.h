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
#include "Entity.h"


class Game
{
public:
    Game();
    ~Game();
    void arRun();

    const float BAR_HEIGHT = 300;
    const float FRAMETIME = 16.667;
    const float WINDOW_WIDTH = 700;
    const float WINDOW_HEIGHT = 400;
    float angle;

    sf::Event eventH;
    sf::Clock gameTime;
    sf::Clock loopTime;
    sf::Time deltaTime;
    sf::RenderWindow gWind;
    sf::RenderStates states;
    sf::View cameraView;

    std::vector<Entity*> mGameEntities;

    void drawObjects(sf::RenderTarget& target);

    bool gameRunning;

    //Entities
    sf::Texture bgtxtr; //Name will change
    sf::Sprite bg;

    Player* player;
    Bar* staminaBar;
    Bar* manaBar;

    //enum LayerType {EntityRenderLayer = 1, BackgroundRenderLayer = 0, ForegroundRenderLayer = 2};

};




#endif // GAME_H_INCLUDED
