#ifndef WORLDRENDERER_H
#define WORLDRENDERER_H

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include <iostream>

class WorldRenderer
{
public:
    WorldRenderer(const std::string fileName);
    sf::Texture bgtxtr; //Name will change
    sf::Sprite bg;

    void update();
    void draw(sf::RenderTarget& target);

};


#endif // WORLDRENDERER_H_INCLUDED
