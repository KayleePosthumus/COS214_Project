#ifndef Rocket_H
#define Rocket_H

#include "Component.h"
#include "Payload.h"

class Rocket
{
private:
    Component *components; //linked list
    Payload *payload;      // linked list

public:
    Rocket();
    virtual ~Rocket();

    void setComponents(Component *components);
    void addComponents(Component *components);
    void setPayload(Payload *payload);
};

#endif