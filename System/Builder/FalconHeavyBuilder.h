#ifndef FALCONHEAVYBUILDER_H
#define FALCONHEAVYBUILDER_H

/** @brief A class that builds FalconHeavy Objects.

    A class which inherits from RocketBuilder that uses the builder design pattern to build FalconHeavy Objects.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "../Settings.h"
#include "../Builder/RocketBuilder.h"
#include "../Spacecraft/FalconRocket/FalconHeavy.h"
#include "../Spacecraft/Dragon/Dragon.h"
#include "../Spacecraft/Dragon/CrewDragon.h"
#include "../Spacecraft/Dragon/DragonSpacecraft.h"
#include "../Spacecraft/Payload.h"
#include "../Component/Falcon9Core.h"
#include "../Component/Engine.h"
#include "../StarlinkSatellite/StarlinkSatellite.h"

class FalconHeavyBuilder : public RocketBuilder
{
private:
    Rocket *_falconHeavy = 0; /**<FalconHeavy rocket that is being built*/

public:
    /** Default constructor. Invokes RocketBuilders constructor.
        */
    FalconHeavyBuilder();
    /** Default destructor.
        */
    virtual ~FalconHeavyBuilder();

    /** Creates a new FalconHeavy Rocket Object
        */
    virtual void ConstructRocket();
    /** Adds FalconHeavy Cores and Merlin Engines to the FalconHeavy Rocket
        */
    virtual void AddCoresAndMerlinEngines();
    /** Adds Vacuum Merlin Engines to the FalconHeavy Rocket
        */
    virtual void AddVacuumMerlinEngines();
    /** Adds Payload Objects to the FalconHeavy Rocket
        @param PayloadType - the type of payload object that needs to be added
        @param numberOfPayloadItems - the amount of payload objects to add to the rocket
        */
    virtual void AddPayload(RocketPayloadType PayloadType, int numberOfPayloadItems = 1);

    /** Accessor that returns the rocket that is constructed
     *  @return The rocket object that is constructed
        */
    Rocket *GetRocket();
};

#endif
