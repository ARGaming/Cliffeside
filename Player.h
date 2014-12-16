#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Arc.h"

class Player : public Entity
{
public:
    Player();
    Player(sf::Vector2f);

    void arHandleEvent(const sf::Event& e);
    void arUpdate(float angle);
    void draw(sf::RenderTarget& target);

    float arGetStamina();
    sf::Vector2f arGetBodyCenter();
    sf::Vector2f arGetViewDir();

    void arSetViewDir(sf::Vector2f);

private:
    float m_stamina;
    sf::Vector2f m_viewDir;
    const double PI = 4.0*atan(1.0);

    Arc m_attackArc;
};

#endif // PLAYER_H_INCLUDED
