#include "Falcon9.h"

using namespace std;

Falcon9::Falcon9(string name) : Rocket(name)
{
    SetHealth(Falcon9Config::Health);
}

Falcon9::~Falcon9()
{
}

float Falcon9::GetHealthPercentage()
{
    return ((float) GetHealth()) / ((float) Falcon9Config::Health) * 100;
}

void Falcon9::TakeLiftOffDamage()
{
    _state = true;
    Rocket::TakeLiftOffDamage();

    Component* current = GetCoreList();
    while(current)
    {
        if(current->GetHealth() <= 0)
        {
            _state = false;
        }

        current = current->successor;
    }

    if(!_state)
        SetHealth(GetHealth() - 0.33*Falcon9Config::Health);

    Rocket::notify();
}

bool Falcon9::GetState()
{
    return _state;
}
