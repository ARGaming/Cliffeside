#include "Player.h"

Player::Player()
    : m_attackArc(0.08f, 90, 100)
{
}

Player::Player(sf::Vector2f initP)
    : m_attackArc(0.08f, 90, 100)
{
    arSetPosition(initP);
    m_viewDir.x = 1;
    m_viewDir.y = 0;

    m_attackArc.arSetPosition(initP);
}

void Player::arHandleEvent(const sf::Event& e)
{
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if (e.mouseButton.button == sf::Mouse::Left)
        {
            m_attackArc.arStartSwing(arGetRotation() - 45); //subtract half of range so that the arc starts before and after the view angle
        }
    }
}

void Player::arUpdate()
{
    sf::Vector2f dir;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir.x -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir.x += 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir.y -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir.y += 1;
    }

    arMovePlayer(dir.x * 10, dir.y * 10);

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
