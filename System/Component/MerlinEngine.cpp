#include "MerlinEngine.h"

using namespace std;

MerlinEngine::MerlinEngine(string name) : Engine(name)
{
    this->SetHealth(MerlinEngineConfig::health);
}
MerlinEngine::MerlinEngine(string name, Component *successor) : Engine(name, successor)
{
    this->SetHealth(MerlinEngineConfig::health);
}
MerlinEngine::~MerlinEngine() {}
