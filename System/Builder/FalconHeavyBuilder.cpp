#include "FalconHeavyBuilder.h"

using namespace std;

FalconHeavyBuilder::FalconHeavyBuilder()
{
}
FalconHeavyBuilder::~FalconHeavyBuilder()
{
}

void FalconHeavyBuilder::ConstructRocket()
{
    this->falconHeavy = new FalconHeavy("FalconHeavyRocket");
}
void FalconHeavyBuilder::AddCoresAndMerlinEngines()
{
    ComponentFactory *coreFactory = new CoreFactory();
    Component **engines = new Component *[Falcon9CoreConfig::numOfMerlinEnginesAttached];

    for (int i = 0; i < FalconHeavyConfig::Falcon9CoresCount; i++)
    {
        for (int j = 0; j < Falcon9CoreConfig::numOfMerlinEnginesAttached; j++)
        {
            j == 0 ? engines[j] = new MerlinEngine("MerlinEngine") : engines[j] = new MerlinEngine("MerlinEngine", engines[j - 1]);
        }

        this->falconHeavy->AddComponents(engines[Falcon9CoreConfig::numOfMerlinEnginesAttached - 1]);
        this->falconHeavy->AddComponents(coreFactory->produce());
    }
}
void FalconHeavyBuilder::AddVacuumMerlinEngines()
{
    ComponentFactory *vacuumMerlinEngineFactory = new VacuumMerlinEngineFactory();
    for (int i = 0; i < FalconHeavyConfig::VacuumEnginesCount; i++)
        this->falconHeavy->AddComponents(vacuumMerlinEngineFactory->produce());
}
void FalconHeavyBuilder::AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems)
{
    // if (PayloadType == RocketPayloadType::dragon)
    // {
    //     vector<Payload *> *payload = new vector<Payload *>(1);
    //     payload->push_back(new Dragon());
    // }
}
Rocket *FalconHeavyBuilder::GetRocket()
{
    return this->falconHeavy;
}
