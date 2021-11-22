#ifndef FALCON9BUILDER_H
#define FALCON9BUILDER_H

#include "../Settings.h"
#include "../Builder/RocketBuilder.h"
#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "../Spacecraft/Dragon/Dragon.h"
#include "../Spacecraft/Dragon/CrewDragon.h"
#include "../Spacecraft/Dragon/DragonSpacecraft.h"
#include "../Spacecraft/Payload.h"
#include "../Component/Falcon9Core.h"
#include "../Component/Engine.h"
#include "../StarlinkSatellite/StarlinkSatellite.h"

class Falcon9Builder : public RocketBuilder
{
private:
    Rocket *_falcon9 = 0;

public:
    Falcon9Builder();
    virtual ~Falcon9Builder();

    virtual void ConstructRocket();
    virtual void AddCoresAndMerlinEngines();
    virtual void AddVacuumMerlinEngines();
    virtual void AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems = 1);

    Rocket *GetRocket();
};

#endif
