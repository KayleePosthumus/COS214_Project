#include "Falcon9Core.h"

using namespace std;

Falcon9Core::Falcon9Core(string name) : Component(name)
{
    Component::SetHealth(Falcon9CoreConfig::health);
}

Falcon9Core::Falcon9Core(string name, Component *successor) : Component(name, successor)
{
    Component::SetHealth(Falcon9CoreConfig::health);
}

Falcon9Core::~Falcon9Core()
{
    while(_engines)
    {
        Component *current = _engines;
        _engines = _engines->successor;
        delete current;
    }
}

void Falcon9Core::AddEngines(Component* merlinEngine)
{
    if(!_engines)
    {
        _engines = merlinEngine;
    }
    else
    {
        Component *current = _engines;
        while(current->successor)
        {
            current = current->successor;
        }

        current->successor = merlinEngine->Clone();
    }
}

void Falcon9Core::AddCore(Component* core)
{
    successor = core;
}

void Falcon9Core::Destroy()
{
    //Destory all engines attached to this core
    Component *current = _engines;
    while(current)
    {
        current->TakeDamage(current->GetHealth());;
        current = current->successor;
    }
}

Component* Falcon9Core::Clone()
{
    Falcon9Core* c = new Falcon9Core("Falcon 9 Core");
    Component* merlinEngine = new MerlinEngine("Merlin Engine");

    for(int i = 0; i < Falcon9Config::MerlinEnginesCount; ++i)
    {
        c->AddEngines(merlinEngine);
    }
    return c;
}