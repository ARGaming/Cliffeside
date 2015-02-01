#ifndef RENDER_H
#define RENDER_H

#include "include.h"
#include "component.h"

class RenderSys : public ComponentSys
{
private:

public:
    virtual void arRender(sf::RenderWindow& window) override;
    virtual void arUpdate(float delta) override;
    virtual void arInit() override;

};

#endif // RENDER_H
