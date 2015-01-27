#include "Player.h"
#include <iostream>
#include <cmath>


Player::Player(sf::Vector2f initP, sf::Vector2f playerSize)
    : m_attackArc(14.5f, 150, 100)
{
    arSetSize(playerSize);
    arSetPosition(initP);
    arSetTexture("Front.png",true);
    arSetTexture("Back.png",false);
    m_viewDir.x = 1;
    m_viewDir.y = 0;

    m_attackArc.arSetPosition(initP);

    m_angle = 0.0;

    m_renderLayer = EntityRenderLayer;

}

void Player::arHandleEvent(const sf::Event& e)
{
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if (e.mouseButton.button == sf::Mouse::Left)
        {
            m_attackArc.arStartSwing(arGetRotation() - (m_attackArc.arGetRange()/2)); //subtract half of range so that the arc starts before and after the view m_angle
            //change 45 to something that accesses arc range?
        }
    }
}

void Player::arUpdate(float angle, sf::View& view)
{

    sf::Vector2f dir;
    m_angle = angle;

    //Handle the textures for the player related to its viewing direction
    arHandleTextureDir();

    //Handle input events
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir.x -= .65; dir.y += .65;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir.x -= .65; dir.y -= .65;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir.x += .65; dir.y += .65;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir.x += .65; dir.y -= .65;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir.x += 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir.y -= 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir.x -= 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir.y += 1;
    }

    //Handle player viewing direction vector
    arHandleViewingDir();

    arRotate(m_angle);

    arMovePlayer(dir.x * 6, dir.y * 6);
    view.move(dir.x * 6, dir.y * 6);
    arSetPosition(m_sprite.getPosition());

    m_attackArc.arUpdate();
    m_attackArc.arSetPosition(m_sprite.getPosition());


}

void Player::draw(sf::RenderTarget& target)
{
    target.draw(arGetSprite());
    target.draw(m_attackArc);

    //Draw arc collision points
    std::vector<sf::Vector2f> arcColPoints = m_attackArc.arGetCollisionPoints();

    for (auto it = arcColPoints.begin(); it != arcColPoints.end(); ++it)
    {
        sf::CircleShape cs(2);
        cs.setPosition(*it);
        target.draw(cs);
    }


}

void Player::arHandleTextureDir()
{
    if(m_angle < 0 and m_angle >= -90)
    {
        arSetTexture("Back.png",false);
        arSetScale(1,1);
    }
    if(m_angle >= 0 and m_angle < 90)
    {
        arSetTexture("Front.png",true);
        arSetScale(1,1);
    }
    if(m_angle < -90 and m_angle >= -180)
    {
        arSetTexture("Back.png",false);
        arSetScale(-1,1);
    }
    if(m_angle >= 90 and m_angle <= 180)
    {
        arSetTexture("Front.png",true);
        arSetScale(-1,1);
    }
}

void Player::arHandleViewingDir()
{
    if (m_angle <= 22.5 and m_angle >= -22.5)
    {
        m_angle = 0;
        arSetViewDir(sf::Vector2f(1, 0));
    }
    else if (m_angle < -22.5 and m_angle >= -67.5)
    {
        m_angle = -45;
        arSetViewDir(sf::Vector2f(std::sqrt(2)/2, -std::sqrt(2)/2));
    }
    else if (m_angle < -67.5 and m_angle >= -112.5)
    {
        m_angle = -90;
        arSetViewDir((sf::Vector2f(0, -1)));
    }
    else if (m_angle < -112.5 and m_angle > -157.5)
    {
        m_angle = -135;
        arSetViewDir((sf::Vector2f(-std::sqrt(2)/2, -std::sqrt(2)/2)));
    }
    else if (m_angle > 22.5 and m_angle <= 67.5)
    {
        m_angle = 45;
        arSetViewDir(sf::Vector2f(std::sqrt(2)/2, std::sqrt(2)/2));
    }
    else if (m_angle > 67.5 and m_angle <= 112.5)
    {
        m_angle = 90;
        arSetViewDir(sf::Vector2f(0, 1));
    }
    else if (m_angle > 112.5 and m_angle <= 157.5)
    {
        m_angle = 135;
        arSetViewDir((sf::Vector2f(-std::sqrt(2)/2, std::sqrt(2)/2)));
    }
    else
    {
        m_angle = 180;
        arSetViewDir(sf::Vector2f(-1, 0));
    }
}


float Player::arGetStamina()
{
    return m_stamina;
}

sf::Vector2f Player::arGetBodyCenter()
{
    sf::Vector2f bodyCenter;

    bodyCenter.x = arGetSize().x/2.0;
    bodyCenter.y = arGetSize().y/2.0;

    return bodyCenter;
}

sf::Vector2f Player::arGetViewDir()
{
    return m_viewDir;
}

void Player::arSetViewDir(sf::Vector2f dir)
{
    m_viewDir = dir;
}
