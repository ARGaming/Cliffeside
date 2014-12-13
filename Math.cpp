#include "Math.h"
#include <iostream>
#include <cmath>

namespace arMath
{
    Math::Math()
    {

    }

    Math::~Math()
    {

    }


    float Math::length(sf::Vector2f vec)
    {
        return (float)sqrtf(vec.x * vec.x + vec.y * vec.y);
    }

    float Math::dotProduct(sf::Vector2f A, sf::Vector2f B)
    {

        return (float)(A.x * B.x + A.y * B.y);
    }

    sf::Vector2f Math::normalize(sf::Vector2f vec)
    {
        sf::Vector2f normVec;
        normVec.x = vec.x / length(vec);
        normVec.y = vec.y / length(vec);

        return normVec;
    }


    float Math::angleBetweenVecs(sf::Vector2f A, sf::Vector2f B)
    {
        float angle = acosf(dotProduct(A, B) / (length(A) * length(B)));
        return angle;
    }

}

