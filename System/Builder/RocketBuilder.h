#ifndef ROCKETBUILDER_H
#define ROCKETBUILDER_H

/** @brief An abstract class that builds Rocket Objects.

    A class that uses the builder design pattern to build Rocket Objects.
    @author Ctrl Alt Defeat
    @date November 2021
    */

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
    /** Default constructor.
        */
    RocketBuilder();
    /** Default destructor.
        */
    virtual ~RocketBuilder();

    /** Abstract. Creates a new Rocket Object
        */
    virtual void ConstructRocket() = 0;
    /** Abstract. Adds FalconHeavy Cores and Merlin Engines to the Rocket
        */
    virtual void AddCoresAndMerlinEngines() = 0;
    /** Abstract. Adds Vacuum Merlin Engines to the Rocket
        */
    virtual void AddVacuumMerlinEngines() = 0;
    /** Abstract. Adds Payload Objects to the FalconHeavy Rocket
        @param PayloadType - the type of payload object that needs to be added
        @param numberOfPayloadItems - the amount of payload objects to add to the rocket
        */
    virtual void AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems = 1) = 0;

    /** Accessor that returns the rocket that is constructed
        */
    virtual Rocket *GetRocket() = 0;

    /** Creates a Human and adds it to the Rocket.
        @return The human object that is added to the rocket
        */
    Human *AddPeople();
    Cargo *AddCargo();
};

#endif
