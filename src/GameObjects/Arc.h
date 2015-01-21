#ifndef ARC_H
#define ARC_H

#include <vector>

#include <SFML/Graphics.hpp>

class Arc : public sf::Drawable
{
public:
    //Speed = fraction of range moved each frame, e.g. 1 speed = reach the end in one frame
    Arc(float speed, float range, float length);

    void arUpdate();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    //Start a swing from the passed angle until the range specified in the constructor
    void arStartSwing(float angle);

    void arSetPosition(const sf::Vector2f& pos);

    float arGetRange();

    //This returns a list of collision points along the current angle of the arc
    //Use with the contains() function of SFML rects
    std::vector<sf::Vector2f> arGetCollisionPoints();

private:
    float m_speed;
    float m_range;
    float m_ticks;
    float m_tickCount;

    sf::RectangleShape m_collider;

    bool m_swinging;
    float m_beginSwingAngle;
};

#endif //ARC_H
