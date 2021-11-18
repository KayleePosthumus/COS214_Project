#include "Falcon9Builder.h"

Falcon9Builder::Falcon9Builder()
{
}
Falcon9Builder::~Falcon9Builder()
{
}

void Falcon9Builder::addCoresAndMerlinEngines()
{
    ComponentFactory *coreFactory = new CoreFactory();
    ComponentFactory *merlinEngineFactory = new MerlinEngineFactory();
    Component **cores = new Component *[Falcon9Config::Falcon9CoresCount * Falcon9CoreConfig::numOfMerlinEnginesAttached];
    Component *prev = 0;
    for (int i = 0; i < Falcon9CoreConfig::numOfMerlinEnginesAttached; i++)
    {
        for (int j = 0; j < Falcon9Config::Falcon9CoresCount; j++)
        {
            cores[j] = coreFactory->produce();
            cores[j]->successor = prev;
            prev = cores[i];
        }
    }
}
void Falcon9Builder::addVacuumMerlinEngines()
{
}
void Falcon9Builder::addPayload(RocketPayloadType PayloadType, int numberOfPayloadItems = 1)
{
}