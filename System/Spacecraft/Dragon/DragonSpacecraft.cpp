#include "DragonSpacecraft.h"

DragonSpacecraft::DragonSpacecraft() 
{
    _maxCargoCapacity = 3307;
}

DragonSpacecraft::~DragonSpacecraft() {}

bool DragonSpacecraft::AddCargo(Cargo* c)
{
    if (_currentCargoCapacity + c->GetWeight() <= _maxCargoCapacity)
    {
        _cargoModules->push_back(c);
        _currentCargoCapacity += c->GetWeight();
        return true;
    }
    return false;
}

// removes first occurrence of the given cargo and does nothing if it is not found
bool DragonSpacecraft::RemoveCargo(Cargo* c)
{
    vector<Cargo*>::iterator it = find(_cargoModules->begin(), _cargoModules->end(), c);

    if (it != _cargoModules->end())
    {
        _currentCargoCapacity -= (*it)->GetWeight();
        _cargoModules->erase(it);
        return true;
    }
    return false;
}