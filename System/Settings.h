#ifndef SETTINGS_H
#define SETTINGS_H

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

class RNG
{
public:
    static const float EngineDamageLiftOffProbability = 0.25;
};

#endif