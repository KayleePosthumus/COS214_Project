#ifndef ROCKETBUILDER_H
#define ROCKETBUILDER_H

#include "../Settings.h"
#include "../SpaceCraft/FalconRocket/Rocket.h"
#include "../Spacecraft/Dragon/Human.h"
#include "../Spacecraft/Dragon/Cargo.h"

#include <iostream>
#include <string>
using namespace std;

class RocketBuilder
{
public:
    RocketBuilder();
    virtual ~RocketBuilder();

    virtual void ConstructRocket() = 0;
    virtual void AddCoresAndMerlinEngines() = 0;
    virtual void AddVacuumMerlinEngines() = 0;
    virtual void AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems = 1) = 0;

    virtual Rocket *GetRocket() = 0;
    Human* AddPeople();
    Cargo* AddCargo();
};

#endif
