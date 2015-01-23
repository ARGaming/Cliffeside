#ifndef PhysicsBody_H
#define PhysicsBody_H

#include <SFML/Graphics.hpp>

class PhysicsBody
{

public:
    PhysicsBody(sf::Sprite sprite, std::string id);
    PhysicsBody(sf::RectangleShape rectShape, std::string id); //Used for arbitrarily positioning the Bounding shape within the entity's body
    PhysicsBody(sf::CircleShape rectShape, std::string id); //Used for arbitrarily positioning the Bounding shape within the entity's body
    ~PhysicsBody();

    void arSetID(std::string id);
    std::string arGetID();

    void arSetBoundBox(sf::FloatRect rect);
    sf::FloatRect& arGetBoundingBox();


private:
    std::string m_id;
    sf::FloatRect m_bounding_box;
    sf::CircleShape m_bounding_circle;
    sf::RectangleShape m_bounding_rectangle;

};


#endif // PhysicsBody_H
