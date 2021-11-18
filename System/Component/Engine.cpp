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