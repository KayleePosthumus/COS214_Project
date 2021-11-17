#include "VacuumMerlinEngine.h"

using namespace std;

VacuumMerlinEngine::VacuumMerlinEngine(string name) : Engine(name)
{
    this->SetHealth(VacuumMerlinEngineConfig::health);
}
VacuumMerlinEngine::~VacuumMerlinEngine() {}
