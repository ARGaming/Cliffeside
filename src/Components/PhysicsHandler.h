#ifndef PHYSICSHANDLER_H
#define PHYSICSHANDLER_H

class PhysicsHandler
{
public:
    PhysicsHandler();
    virtual void handlePhysics(sf::Shape shape) = 0;

private:
    bool m_collisionDetected;

};


#endif // PHYSICSHANDLER_H
