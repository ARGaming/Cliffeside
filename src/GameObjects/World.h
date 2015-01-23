#ifndef WORLD_H
#define WORLD_H

#include<SFML/Graphics.hpp>
#include "../Components/PhysicsBody.h"

class World
{
public:
    World(sf::RenderTarget& target);
    ~World();

    sf::View& arGetCameraView();

    void arRender(sf::RenderTarget& target);
private:
    //Entities
    sf::Texture m_background_texture; //Name will change
    sf::Sprite m_background;

    sf::View m_camera_view;

    PhysicsBody* m_top_wall;
    PhysicsBody* m_bottom_wall;
    PhysicsBody* m_right_wall;
    PhysicsBody* m_left_wall;

    sf::RectangleShape left_bound_rect;
    sf::RectangleShape right_bound_rect;
    sf::RectangleShape top_bound_rect;
    sf::RectangleShape bottom_bound_rect;

    std::string m_world_boundaries;
};



#endif // WORLD_H
