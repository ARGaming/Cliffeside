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
}
