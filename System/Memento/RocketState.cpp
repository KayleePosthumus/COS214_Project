#include "RocketState.h"

RocketState::RocketState(string name, int rocketHealth, vector<int> coreHealth, int vacuumHealth)
{
    _name = name;
    _rocketHealth = rocketHealth;
    _coreHealth = coreHealth;
    _vacuumHealth = vacuumHealth;
}

RocketState::~RocketState()
{
    //delete _components;
    //delete _subjectStage;
}

int RocketState::GetHealth()
{
    return _rocketHealth;
}

string RocketState::GetName()
{
    return _name;
}

vector<int> RocketState::GetCoreHealth()
{
    return _coreHealth;
}

int RocketState::GetVacuumHealth()
{
    return _vacuumHealth;
}

Stage* RocketState::GetStage()
{
    return _subjectStage;
}
