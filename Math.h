#ifndef MATH_H
#define MATH_H

#include<SFML/Graphics.hpp>


class Math
{
public:
    Math();
    ~Math();
    float dotProduct(sf::Vector2f, sf::Vector2f);
    float length(sf::Vector2f);
    float angleBetweenVecs(sf::Vector2f, sf::Vector2f);
    sf::Vector2f normalize(sf::Vector2f);

};


#endif // MATH_H_INCLUDED
