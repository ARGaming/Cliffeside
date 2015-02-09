#include "player.h"

Player::Player()
{

}

void Player::init()
{
    setID("player");
    shoot = false;
    setTexture("assets/front.png", "assets/back.png");
    setPosition(sf::Vector2f(400, 400));
    setSpeed(300);
    setMotion(sf::Vector2i(0,  0));
    setAlive(false);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(-1, -1));

        //Flip the texture to view the direction the player is going, left = looking back
        flipTexture(false);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(-1, 1));

        //Flip the texture to view the direction the player is going, left = looking back
        flipTexture(false);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(1, -1));

        //Flip the texture to view the direction the player is going, left = looking back
        flipTexture(true);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(1, 1));

        //Flip the texture to view the direction the player is going, left = looking back
        flipTexture(true);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(-1, 0));

        //Flip the texture to view the direction the player is going, left = looking back
        flipTexture(false);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        setMotion(sf::Vector2i(1, 0));

        //Flip the texture to view the direction the player is going, left = looking back
        flipTexture(true);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(0, -1));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //Motion is the direction the player is going to be moving
        setMotion(sf::Vector2i(0, 1));
    }


}
