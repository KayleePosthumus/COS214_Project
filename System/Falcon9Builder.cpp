#include "Falcon9Builder.h"

Falcon9Builder::Falcon9Builder()
{
}
Falcon9Builder::~Falcon9Builder()
{
}

void Falcon9Builder::addCores()
{
    ComponentFactory *componentFactory = new CoreFactory();
    Core **cores = new Core *[Falcon9Config::Falcon9CoresCount];
    for (int i = 0; i < Falcon9Config::Falcon9CoresCount; i++)
    {
        cores[i] = componentFactory->produce();
    }
}
void Falcon9Builder::addEngines()
{
}
void Falcon9Builder::addPayload(SpaceCraft *spaceCraft, RocketPayloadType PayloadType, int numberOfPayloadItems = 1)
{
}