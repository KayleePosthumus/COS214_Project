#ifndef ROCKETBUILDER_H
#define ROCKETBUILDER_H

#include "../Settings.h"
#include "../SpaceCraft/FalconRocket/Rocket.h"

class RocketBuilder
{
private:
public:
    RocketBuilder();
    virtual ~RocketBuilder();

    virtual void ConstructRocket() = 0;
    virtual void AddCoresAndMerlinEngines() = 0;
    virtual void AddVacuumMerlinEngines() = 0;
    virtual void AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems = 1) = 0;

    virtual Rocket *GetRocket() = 0;
};

#endif
