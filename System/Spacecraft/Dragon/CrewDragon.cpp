#include "CrewDragon.h"

CrewDragon::CrewDragon(string name) : Dragon(name)
{
    _maxCargoCapacity = 2507;
}

CrewDragon::~CrewDragon()
{
    while(!_crewMembers.empty()) {
		if (_crewMembers.back())
			delete _crewMembers.back();

        _crewMembers.pop_back();
	}
}

bool CrewDragon::AddCargo(Cargo* c)
{
    if (_currentCargoCapacity + c->GetWeight() <= _maxCargoCapacity)
    {
        _cargoModules.push_back(c);
        _currentCargoCapacity += c->GetWeight();
        return true;
    }
    return false;
}

// removes first occurrence of the given cargo. Returns true if cargo is found and false if not found
bool CrewDragon::RemoveCargo(Cargo* c)
{
    vector<Cargo*>::iterator it = find(_cargoModules.begin(), _cargoModules.end(), c);

    if (it != _cargoModules.end())
    {
        _currentCargoCapacity -= (*it)->GetWeight();
        _cargoModules.erase(it);
        return true;
    }
    return false;
}

bool CrewDragon::AddCrew(Human* h)
{
    if (_crewMembers.size() < _maxCrew)
    {
        _crewMembers.push_back(h);
        return true;
    }
    return false;
}

bool CrewDragon::RemoveCrew(Human* h)
{
    vector<Human*>::iterator it = find(_crewMembers.begin(), _crewMembers.end(), h);

    if (it != _crewMembers.end())
    {
        _crewMembers.erase(it);
        return true;
    }
    return false;
}

string CrewDragon::GetPassengers()
{
    string out = "";

    for(size_t i = 0; i < _crewMembers.size(); ++i)
    {
        out += _crewMembers[i]->GetName() + "\n";
    }

    return out;
}

Payload* CrewDragon::Clone()
{
    CrewDragon* c = new CrewDragon(GetName());

    for(size_t i = 0; i < _cargoModules.size(); ++i)
    {
        c->AddCargo(_cargoModules[i]);
    }

    for(size_t i = 0; i < _crewMembers.size(); ++i)
    {
        c->AddCrew(_crewMembers[i]);
    }

    return c;
}