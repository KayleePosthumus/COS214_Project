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
