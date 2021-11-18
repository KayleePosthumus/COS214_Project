#ifndef FALCONHeavyBUILDER_H
#define FALCONHeavyBUILDER_H

#include "../Settings.h"
#include "../Builder/RocketBuilder.h"
#include "../Spacecraft/SpaceCraft.h"
#include "../Spacecraft/FalconRocket/FalconHeavy.h"
#include "../Spacecraft/Dragon/Dragon.h"
#include "../Spacecraft/Dragon/CrewDragon.h"
#include "../Spacecraft/Payload.h"
#include "../Component/Core.h"
#include "../Component/Engine.h"
#include "../Factory/CoreFactory.h"
#include "../Factory/MerlinEngineFactory.h"
#include "../Factory/VacuumMerlinEngineFactory.h"
#include "../StarlinkSatellite/StarlinkSatellite.h"

class FalconHeavyBuilder : public RocketBuilder
{
private:
    FalconHeavy *falconHeavy = 0;

public:
    FalconHeavyBuilder();
    virtual ~FalconHeavyBuilder();

    virtual void ConstructRocket();
    virtual void AddCoresAndMerlinEngines();
    virtual void AddVacuumMerlinEngines();
    virtual void AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems = 1);

    Rocket *GetRocket();
};

#endif
