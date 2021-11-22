#include "RocketState.h"

RocketState::RocketState(string n, int h, Component* c, Stage* s)
{
    _name = n;
    _health = h;
    _components = c->Clone();
    _subjectStage = s->Clone();  // TODO: copy constructor
}

RocketState::~RocketState()
{
    delete _components;
    //delete _subjectStage;
}

int RocketState::GetHealth()
{
    return _health;
}

string RocketState::GetName()
{
    return _name;
}

Component* RocketState::GetComponents()
{
    return _components;
}

Stage* RocketState::GetStage()
{
    return _subjectStage;
}
