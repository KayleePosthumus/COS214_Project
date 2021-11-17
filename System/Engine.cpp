#include "Engine.h"

using namespace std;

Engine::Engine(string name) : Component(name) {}
Engine::~Engine() {}

void Engine::Destroy()
{
    if (RNG::EngineDestroyedDamagingNeighboringComponents())
    {
        successor->TakeDamage(RNG::RandomDamageToComponents());
    }
}