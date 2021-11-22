#ifndef FALCON9BUILDER_H
#define FALCON9BUILDER_H

/** @brief A class that builds Falcon9 Objects.

    A class which inherits from RocketBuilder that uses the builder design pattern to build Falcon9 Objects.
    @author Ctrl Alt Defeat
    @date November 2021
    */

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
    Rocket *_falcon9 = 0; /**<Falcon9 rocket that is being built*/

public:
    /** Default constructor. Invokes RocketBuilders constructor.
        */
    Falcon9Builder();
    /** Default destructor.
        */
    virtual ~Falcon9Builder();

    /** Creates a new Falcon9 Rocket Object
        */
    virtual void ConstructRocket();
    /** Adds Falcon9 Cores and Merlin Engines to the Falcon9 Rocket
        */
    virtual void AddCoresAndMerlinEngines();
    /** Adds Vacuum Merlin Engines to the Falcon9 Rocket
        */
    virtual void AddVacuumMerlinEngines();
    /** Adds Payload Objects to the Falcon9 Rocket
        @param PayloadType - the type of payload object that needs to be added
        @param numberOfPayloadItems - the amount of payload objects to add to the rocket
        */
    virtual void AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems = 1);

    /** Accessor that returns the rocket that is constructed
     * @return The rocket object that is constructed
        */
    Rocket *GetRocket();
};

#endif
