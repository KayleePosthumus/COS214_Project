#include "Dragon.h"

Dragon::Dragon(string name) : Payload(name)
{
}

Dragon::~Dragon()
{
    while(!_cargoModules.empty()) {
		if (_cargoModules.back())
		{
			delete _cargoModules.back();
		}

		_cargoModules.pop_back();
	}
}

string Dragon::GetCargo()
{
    string out = "";

    for(size_t i = 0; i < _cargoModules.size(); ++i)
    {
        out += _cargoModules[i]->GetDescription() + " : " + to_string(_cargoModules[i]->GetWeight()) + " kg\n";
    }

    return out;
}

void Dragon::CommunicateSatellite()
{

}

void Dragon::CommunicateGround()
{

}

Iterator* Dragon::CreateIterator()
{
    return new Iterator();
}