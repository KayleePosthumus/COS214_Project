#include "RocketMemento.h"

RocketMemento::RocketMemento(string name, int rocketHealth, vector<int> coreHealth, int vacuumHealth) 
{
    _state = new RocketState(name, rocketHealth, coreHealth, vacuumHealth);
}

RocketMemento::~RocketMemento()
{
    delete _state;
}

RocketState* RocketMemento::getState()
{
    return _state;
}