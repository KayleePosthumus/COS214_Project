#include "Falcon9Core.h"

using namespace std;

Falcon9Core::Falcon9Core(string name) : Component(name)
{
    this->SetHealth(Falcon9CoreConfig::health);
}
Falcon9Core::Falcon9Core(string name, Component *successor) : Component(name, successor)
{
    this->SetHealth(Falcon9CoreConfig::health);
}

Falcon9Core::~Falcon9Core() {}

void Falcon9Core::Destroy()
{
    int i = Falcon9CoreConfig::numOfMerlinEnginesAttached;
    Component *component = this->successor;
    //destroy engines attached to this
    while (component != 0 && i > 0)
    {
        if (component)
            component->TakeDamage(component->GetHealth()); // destroy engines attached Enginex9->Core->Enginesx9->Core
        component = component->successor;
        i--;
    }
}

void Falcon9Core::TransitionIntoStageTwo(Component *prev)
{
    prev->successor = this->successor;

    if (this->successor)
    {
        this->successor->TransitionIntoStageTwo(prev);
    }
}