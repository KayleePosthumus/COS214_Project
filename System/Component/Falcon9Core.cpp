#include "Falcon9Core.h"

using namespace std;

Falcon9Core::Falcon9Core(string name) : Core(name)
{
    this->SetHealth(Falcon9CoreConfig::health);
}
Falcon9Core::~Falcon9Core() {}

void Falcon9Core::Destroy()
{
    int i = Falcon9CoreConfig::numOfMerlinEnginesAttached;
    //destroy engines attached to this
    while (this->successor != 0 && i > 0)
    {
        this->successor->TakeDamage(this->successor->GetHealth()); // destroy engines attached
        i--;
    }
}