#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
    Player();
    Player(sf::Vector2f);
    float arGetStamina();

private:
    float m_stamina;

};



#endif // PLAYER_H_INCLUDED
