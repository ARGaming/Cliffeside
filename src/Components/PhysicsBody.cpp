#include "PhysicsBody.h"

PhysicsBody::PhysicsBody(sf::Sprite sprite, std::string id)
{
    m_bounding_box = sprite.getGlobalBounds();
    m_id = id;
}

PhysicsBody::PhysicsBody(sf::CircleShape shape, std::string id)
{
    m_bounding_circle = shape;
    m_id = id;
}

PhysicsBody::PhysicsBody(sf::RectangleShape shape, std::string id)
{

    m_bounding_rectangle = shape;
    m_id = id;
}

PhysicsBody::~PhysicsBody()
{

}

sf::FloatRect& PhysicsBody::arGetBoundingBox()
{
    return m_bounding_box;
}

void PhysicsBody::arSetBoundBox(sf::FloatRect rect)
{
    m_bounding_box = rect;
}

void PhysicsBody::arSetID(std::string id)
{
    m_id = id;
}

std::string PhysicsBody::arGetID()
{
    return m_id;
}
