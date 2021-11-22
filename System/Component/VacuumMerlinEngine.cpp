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