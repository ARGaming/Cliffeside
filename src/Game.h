#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include "Core/Math.h"
#include "GameObjects/Player.h"
#include "GameObjects/Arc.h"
#include "GameObjects/Bar.h"
#include "GameObjects/World.h"


class Game
{
public:
    Game();
    ~Game();
    void arRun();

    const float BAR_WIDTH = 200;
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

    std::vector<Entity*> mGameEntities;
    std::vector<std::vector<PhysicsBody*>> mPhysicsWorldBodies;

    void drawObjects(sf::RenderTarget& target);

    bool gameRunning;

    Player* player;
    Bar* staminaBar;
    Bar* manaBar;
    World* world;

    //enum LayerType {EntityRenderLayer = 1, BackgroundRenderLayer = 0, ForegroundRenderLayer = 2};


};




#endif // GAME_H_INCLUDED
