#include "RocketMemento.h"

RocketMemento::RocketMemento(string n, int h, Component* c, Stage* s) 
{
    _state = new RocketState(n, h, c, s);
}

RocketMemento::~RocketMemento()
{
    delete _state;
}

RocketState* RocketMemento::getState()
{
    return _state;
}