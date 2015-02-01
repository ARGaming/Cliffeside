#include "input.h"

InputSys::InputSys()
{

}

void InputSys::arHandleWindowEvents(sf::RenderWindow& window, sf::Event& event)
{
    if(event.type == sf::Event::Closed)
    {
        window.close();
    }

}
