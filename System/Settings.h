#ifndef SETTINGS_H
#define SETTINGS_H

#include <cstdlib>

///////////////////////////////////////////////////////
// Rockets
///////////////////////////////////////////////////////

enum RocketPayloadType
{
    satellites,
    dragon,
    crewDragon,
    count
};

struct Falcon9Config
{
    static const int Falcon9CoresCount = 1;
    static const int MerlinEnginesCount = 9;
    static const int VacuumEnginesCount = 1;
    static const int SatelliteLimit = 60;
};

struct FalconHeavyConfig
{
    static const int Falcon9CoresCount = 3;
    static const int MerlinEnginesCount = 27;
    static const int VacuumEnginesCount = 1;
};

///////////////////////////////////////////////////////
// SpaceCrafts
///////////////////////////////////////////////////////

struct DragonConfig
{
    static const bool CanCarryPayload = 1;
    static const bool CanCarryCrew = 0;
};

struct CrewDragonConfig
{
    static const bool CanCarryPayload = 1;
    static const bool CanCarryCrew = 0;
};

///////////////////////////////////////////////////////
// Components
///////////////////////////////////////////////////////

struct MerlinEngineConfig
{
    static const int health = 100;
};

struct VacuumMerlinEngineConfig
{
    static const int health = 70;
};

struct Falcon9CoreConfig
{
    static const int health = 50;
    static const int numOfMerlinEnginesAttached = 9;
};

///////////////////////////////////////////////////////
// RNG Based events
///////////////////////////////////////////////////////
class RNG // RNG values are based on integer percentages.
{
private:
    static const int MaxComponentDamage = 50;
    static const int MinComponentDamage = 10;

    static const int EngineDamageLiftOffProbability = 25;
    static const int EngineDestroyedDamagingNeighboringComponentsProbability = 25;

    static bool DetermineProbability(float probability)
    {
        return (rand() % 100) + 1 < probability;
    };

public:
    static int RandomDamageToComponents() { return (rand() % MaxComponentDamage) + MinComponentDamage; };

    static bool EngineDamageLiftOff() { return DetermineProbability(EngineDamageLiftOffProbability); };
    static bool EngineDestroyedDamagingNeighboringComponents() { return DetermineProbability(EngineDestroyedDamagingNeighboringComponentsProbability); };
};

#endif