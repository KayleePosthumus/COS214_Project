#include "Engine.h"

using namespace std;

Engine::Engine(string name) : Component(name) {}
Engine::Engine(string name, Component *successor) : Component(name, successor) {}

Engine::~Engine() {}

void Engine::Destroy()
{
    if (RNG::EngineDestroyedDamagingNeighboringComponents())
    {
        if (successor)
            successor->TakeDamage(RNG::RandomDamageToComponents()); // Randomly Damage neighboring engines
    }
}

void Engine::TransitionIntoStageTwo(Component *prev)
{
}

Component *Engine::Clone()
{
    Engine *c; // new Component

    if (this->successor == nullptr)
    {
        c = new Engine(this->GetName());
    }
    else
    {
        Component *s = this->successor->Clone();
        c = new Engine(this->GetName(), s);
    }

    c->SetHealth(this->GetHealth());
    return c;
}