#ifndef FALCON9BUILDER_H
#define FALCON9BUILDER_H

#include "Settings.h"
#include "SpaceCraft.h"
#include "Falcon9.h"
#include "Core.h"
#include "Engine.h"
#include "Payload.h"
#include "CoreFactory.h"

class Falcon9Builder
{
private:
    Falcon9 *falcon9 = 0;

public:
    Falcon9Builder();
    virtual ~Falcon9Builder();

    virtual void addCores();
    virtual void addEngines();
    virtual void addPayload(SpaceCraft *spaceCraft, RocketPayloadType PayloadType, int numberOfPayloadItems = 1);
};

#endif
