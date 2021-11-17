#ifndef ROCKETBUILDER_H
#define ROCKETBUILDER_H

#include "Settings.h"
#include "SpaceCraft.h"

class RocketBuilder
{
private:
public:
    RocketBuilder();
    virtual ~RocketBuilder();

    virtual void addCores() = 0;
    virtual void addEngines() = 0;
    virtual void addPayload(SpaceCraft *spaceCraft, RocketPayloadType PayloadType) = 0;
};

#endif
