#ifndef SETTINGS_H
#define SETTINGS_H

#include <cstdlib>

enum RocketCargoType
{
    satellites,
    count
}

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

struct DragonConfig
{
    static const bool CanCarryCargo = 1;
    static const bool CanCarryCrew = 0;
};

struct CrewDragonConfig
{
    static const bool CanCarryCargo = 1;
    static const bool CanCarryCrew = 0;
};

class RNG // RNG values are based on integer percentages.
{
private:
    static const int EngineDamageLiftOffProbability = 25;

    static bool DetermineProbability(float probability)
    {
        return (rand() % 100) + 1 < probability;
    };

public:
    static bool EngineDamageLiftOff() { return DetermineProbability(this->EngineDamageLiftOffProbability); };
};

#endif