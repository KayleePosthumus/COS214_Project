#ifndef ROCKETPOWEREDSPACECRAFT_H
#define ROCKETPOWEREDSPACECRAFT_H

#include "SpaceCraft.h"
#include "Falcon9Core.h"
#include "MerlinEngine.h"
#include "VacuumMerlinEngine.h"

class RocketPoweredSpaceCraft : public SpaceCraft
{
private:
    Falcon9Core **cores;
    MerlinEngine **merlinEngines;
    VacuumMerlinEngine **vacuumMerlinEngines;

public:
    RocketPoweredSpaceCraft();
    ~RocketPoweredSpaceCraft();
};

#endif