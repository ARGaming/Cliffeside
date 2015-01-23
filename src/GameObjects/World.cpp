#include "World.h"

World::World(sf::RenderTarget& target)
{
    m_camera_view.setCenter(300, 200);
    m_camera_view.setSize(600, 400);
    target.setView(m_camera_view);

    //Background
    m_background_texture.loadFromFile("badBG.png");
    m_background_texture.setSmooth(true);
    m_background.setTexture(m_background_texture);
    m_background.setScale(1.6, 1.6);

    m_world_boundaries = "World_Bounds";

    left_bound_rect.setSize(sf::Vector2f(100, 1150));
    left_bound_rect.setOutlineColor(sf::Color::Blue);
    left_bound_rect.setFillColor(sf::Color::Transparent);
    left_bound_rect.setOutlineThickness(1);
    left_bound_rect.setPosition(sf::Vector2f(-100, 0));

    right_bound_rect.setSize(sf::Vector2f(100, 1150));
    right_bound_rect.setOutlineColor(sf::Color::Blue);
    right_bound_rect.setFillColor(sf::Color::Transparent);
    right_bound_rect.setOutlineThickness(1);
    right_bound_rect.setPosition(sf::Vector2f(2049.5, 0));

    top_bound_rect.setSize(sf::Vector2f(2050, 100));
    top_bound_rect.setOutlineColor(sf::Color::Blue);
    top_bound_rect.setFillColor(sf::Color::Transparent);
    top_bound_rect.setOutlineThickness(1);
    top_bound_rect.setPosition(sf::Vector2f(0, -100));

    bottom_bound_rect.setSize(sf::Vector2f(2050, 100));
    bottom_bound_rect.setOutlineColor(sf::Color::Blue);
    bottom_bound_rect.setFillColor(sf::Color::Transparent);
    bottom_bound_rect.setOutlineThickness(1);
    bottom_bound_rect.setPosition(sf::Vector2f(0, 1151));



    /*
    sf::RectangleShape right_bound_rect;
    sf::RectangleShape top_bound_rect;
    sf::RectangleShape bottom_bound_rect;*/

    m_left_wall = new PhysicsBody(left_bound_rect, m_world_boundaries);

}

World::~World()
{

}

sf::View& World::arGetCameraView()
{
    return m_camera_view;
}


void World::arRender(sf::RenderTarget& target)
{
    target.draw(m_background);

    //Debug only
    target.draw(left_bound_rect);
    target.draw(right_bound_rect);
    target.draw(top_bound_rect);
    target.draw(bottom_bound_rect);
}
