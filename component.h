#ifndef ComponentSys_H
#define ComponentSys_H

#include "SystemManager.h"

class SystemManager;

class ComponentSys
{
private:

protected:

public:
    ComponentSys();
    ~ComponentSys();
    virtual void arUpdate(float delta) = 0;
    virtual void arInit() = 0;
    virtual void arRender(sf::RenderWindow& window) = 0;
};



#endif // ComponentSys_H
