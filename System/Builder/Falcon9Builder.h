#ifndef FALCON9BUILDER_H
#define FALCON9BUILDER_H

#include "../Settings.h"
#include "../Spacecraft/SpaceCraft.h"
#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "../Component/Core.h"
#include "../Component/Engine.h"
#include "../Spacecraft/Payload.h"
#include "../Factory/CoreFactory.h"
#include "../Factory/MerlinEngineFactory.h"

class Falcon9Builder
{
private:
    Falcon9 *falcon9 = 0;

public:
    Falcon9Builder();
    virtual ~Falcon9Builder();

    virtual void addCoresAndMerlinEngines();
    virtual void addVacuumMerlinEngines();
    virtual void addPayload(RocketPayloadType, int);

    Rocket *GetRocket();
};

#endif
