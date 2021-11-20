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

Component* MerlinEngine::Clone()
{
    MerlinEngine* c; // new Component

    if (this->successor == nullptr)
    {
        c = new MerlinEngine(this->GetName());
    }
    else
    {
        Component* s = this->successor->Clone();
        c = new MerlinEngine(this->GetName(), s);
    }
    
    c->SetHealth(this->GetHealth());
    return c;
}