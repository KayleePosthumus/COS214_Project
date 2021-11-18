#ifndef FALCON9BUILDER_H
#define FALCON9BUILDER_H

#include "../Settings.h"
#include "../Builder/RocketBuilder.h"
#include "../Spacecraft/SpaceCraft.h"
#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "../Spacecraft/Dragon/Dragon.h"
#include "../Spacecraft/Dragon/CrewDragon.h"
#include "../Spacecraft/Payload.h"
#include "../Component/Core.h"
#include "../Component/Engine.h"
#include "../Factory/CoreFactory.h"
#include "../Factory/MerlinEngineFactory.h"
#include "../Factory/VacuumMerlinEngineFactory.h"
#include "../StarlinkSatellite/StarlinkSatellite.h"

class Falcon9Builder : public RocketBuilder
{
private:
    Falcon9 *falcon9 = 0;

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
