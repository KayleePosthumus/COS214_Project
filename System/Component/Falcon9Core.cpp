#include "Falcon9Core.h"

using namespace std;

Falcon9Core::Falcon9Core(string name) : Core(name)
{
    this->SetHealth(Falcon9CoreConfig::health);
}
Falcon9Core::Falcon9Core(string name, Component *successor) : Core(name, successor)
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

Component* Falcon9Core::Clone()
{
    Falcon9Core* c; // new Component

    if (this->successor == nullptr)
    {
        c = new Falcon9Core(this->GetName());
    }
    else
    {
        Component* s = this->successor->Clone();
        c = new Falcon9Core(this->GetName(), s);
    }
    
    c->SetHealth(this->GetHealth());
    return c;
}