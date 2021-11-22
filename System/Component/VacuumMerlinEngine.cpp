#include "VacuumMerlinEngine.h"

using namespace std;

VacuumMerlinEngine::VacuumMerlinEngine(string name) : Engine(name)
{
    this->SetHealth(VacuumMerlinEngineConfig::health);
}
VacuumMerlinEngine::VacuumMerlinEngine(string name, Component *successor) : Engine(name, successor)
{
    this->SetHealth(VacuumMerlinEngineConfig::health);
}
VacuumMerlinEngine::~VacuumMerlinEngine() {}

void VacuumMerlinEngine::TransitionIntoStageTwo(Component *prev)
{
    if (this->successor)
    {
        this->successor->TransitionIntoStageTwo(this);
    }
}
Component *VacuumMerlinEngine::Clone()
{
    VacuumMerlinEngine *c; // new Component

    if (this->successor == nullptr)
    {
        c = new VacuumMerlinEngine(this->GetName());
    }
    else
    {
        Component *s = this->successor->Clone();
        c = new VacuumMerlinEngine(this->GetName(), s);
    }

    c->SetHealth(this->GetHealth());
    return c;
}