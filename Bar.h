#ifndef BAR_H
#define BAR_H

#include <SFML/Graphics.hpp>

class Bar : public sf::Drawable
{
public:
    Bar(sf::Vector2f size, sf::Color color);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void arSetPosition(sf::Vector2f pos);
    void arFill(float percentage);

private:
    sf::RectangleShape m_shape;
    float m_percentage;
};

#endif //BAR_H
