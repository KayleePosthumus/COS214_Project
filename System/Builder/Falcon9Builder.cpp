#include "Falcon9Builder.h"

using namespace std;

Falcon9Builder::Falcon9Builder()
{
}
Falcon9Builder::~Falcon9Builder()
{
}

void Falcon9Builder::ConstructRocket()
{
    this->falcon9 = new Falcon9("Falcon9Rocket");
}
void Falcon9Builder::AddCoresAndMerlinEngines()
{
    ComponentFactory *coreFactory = new CoreFactory();
    Component **engines = new Component *[Falcon9CoreConfig::numOfMerlinEnginesAttached];

    for (int i = 0; i < Falcon9Config::Falcon9CoresCount; i++)
    {
        for (int j = 0; j < Falcon9CoreConfig::numOfMerlinEnginesAttached; j++)
        {
            j == 0 ? engines[j] = new MerlinEngine("MerlinEngine") : engines[j] = new MerlinEngine("MerlinEngine", engines[j - 1]);
        }

        this->falcon9->AddComponents(engines[Falcon9CoreConfig::numOfMerlinEnginesAttached - 1]);
        this->falcon9->AddComponents(coreFactory->produce());
    }
}
void Falcon9Builder::AddVacuumMerlinEngines()
{
    ComponentFactory *vacuumMerlinEngineFactory = new VacuumMerlinEngineFactory();
    for (int i = 0; i < Falcon9Config::VacuumEnginesCount; i++)
        this->falcon9->AddComponents(vacuumMerlinEngineFactory->produce());
}
void Falcon9Builder::AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems)
{

    // if (PayloadType == RocketPayloadType::satellites)
    // {
    //     numberOfPayloadItems > Falcon9Config::SatelliteLimit ? numberOfPayloadItems = Falcon9Config::SatelliteLimit : numberOfPayloadItems = numberOfPayloadItems;
    //     vector<Payload *> *payload = new vector<Payload *>(numberOfPayloadItems);

    //     for (int i = 0; i < numberOfPayloadItems; i++)
    //     {
    //         payload->push_back(new StarlinkSatellite());
    //     }
    //     this->falcon9->SetPayload(payload);
    // }

    // if (PayloadType == RocketPayloadType::dragon)
    // {
    //     vector<Payload *> *payload = new vector<Payload *>(1);
    //     payload->push_back(new Dragon());
    // }
}
Rocket *Falcon9Builder::GetRocket()
{
    return this->falcon9;
}
