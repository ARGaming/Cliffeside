#ifndef EVENT_H
#define EVENT_H

#include "include.h"

class InputSys
{
private:

public:
    InputSys();

    void arHandleWindowEvents(sf::RenderWindow& window, sf::Event& event);

};

#endif // EVENT_H

