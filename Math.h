#ifndef MATH_H
#define MATH_H

#include<SFML/Graphics.hpp>

namespace arMath
{
    class Math
    {
    public:
        Math();
        ~Math();
        static float dotProduct(sf::Vector2f, sf::Vector2f);
        static float length(sf::Vector2f);
        static float angleBetweenVecs(sf::Vector2f, sf::Vector2f);
        static sf::Vector2f normalize(sf::Vector2f);

    };


}

#endif // MATH_H_INCLUDED
