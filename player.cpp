#include "player.h"

Player::Player(std::string id, sf::Vector2f position)
{
    setID(id);
    shoot = false;
    setTexture("assets/front.png", "assets/back.png");
    setPosition(position);
    registerEntity(this);
    setSpeed(300);
    setMotion(sf::Vector2i(0,  0));
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(getSprite());
}

void Player::update(float delta)
{
    //Handle input
    handleInput();

    //Updates the player position with delta to smoothly interpolate the movement.
    updatePosition(delta);
}

void Player::handleInput()
{
    setMotion(sf::Vector2i(0, 0));

    //Player input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(-1, 0));

        //Flip the texture to view the direction the player is going, left = looking back
        flipTexture(false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        setMotion(sf::Vector2i(1, 0));

        //Flip the texture to view the direction the player is going, left = looking back
        flipTexture(true);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(0, -1));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(0, 1));
    }

    std::cout << "View dir: " << getViewDir().x << ", " << getViewDir().y << "\n\n";
}
