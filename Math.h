#ifndef MATH_H
#define MATH_H

#include<SFML/Graphics.hpp>

namespace arMath
{
    const double PI = 4.0*atan(1.0);
    float dotProduct(sf::Vector2f, sf::Vector2f);
    float length(sf::Vector2f);
    float angleBetweenVecs(sf::Vector2f, sf::Vector2f);
    sf::Vector2f normalize(sf::Vector2f);
}

#endif // MATH_H_INCLUDED
