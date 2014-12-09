#ifndef ARC_H
#define ARC_H

#include <SFML/Graphics.hpp>

class Arc : public sf::Drawable
{
public:
    Arc(float speed, float range, float length);
    void update(float dt);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void startSwing(float angle);

    void setPosition(const sf::Vector2f& pos);

    sf::FloatRect getCollider();

private:
    float m_speed;
    float m_range;

    sf::RectangleShape m_collider;

    bool m_swinging;
    float m_swingPercentage;
    float m_beginSwingAngle;
};

#endif //ARC_H
