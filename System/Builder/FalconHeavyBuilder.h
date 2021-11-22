#ifndef FALCONHeavyBUILDER_H
#define FALCONHeavyBUILDER_H

#include "../Settings.h"
#include "../Builder/RocketBuilder.h"
#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "../Spacecraft/Dragon/Dragon.h"
#include "../Spacecraft/Dragon/CrewDragon.h"
#include "../Spacecraft/Dragon/DragonSpacecraft.h"
#include "../Spacecraft/Payload.h"
#include "../Component/Falcon9Core.h"
#include "../Spacecraft/FalconRocket/FalconHeavy.h"
#include "../Component/Engine.h"
#include "../StarlinkSatellite/StarlinkSatellite.h"

class FalconHeavyBuilder : public RocketBuilder
{
private:
    Rocket *_falconHeavy = 0;

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
