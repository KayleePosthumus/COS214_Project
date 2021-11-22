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

void MerlinEngine::TransitionIntoStageTwo(Component *prev)
{
    prev->successor = this->successor;

    if (this->successor)
    {
        this->successor->TransitionIntoStageTwo(prev);
    }
}