#include "FalconHeavy.h"

using namespace std;

FalconHeavy::FalconHeavy(string name) : Rocket(name)
{
    SetHealth(FalconHeavyConfig::Health);
}

FalconHeavy::~FalconHeavy()
{
}

float FalconHeavy::GetHealthPercentage()
{
    return ((float) GetHealth()) / ((float) FalconHeavyConfig::Health) * 100;
}

void FalconHeavy::TakeLiftOffDamage()
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
        SetHealth(GetHealth() - 0.33*FalconHeavyConfig::Health);

    Rocket::notify();
}

bool FalconHeavy::GetState()
{
    return _state;
}
