#ifndef VACUUMMERLINENGINEFACTORY_H
#define VACUUMMERLINENGINEFACTORY_H

#include "ComponentFactory.h"
#include "../Component/VacuumMerlinEngine.h"

class VacuumMerlinEngineFactory : public ComponentFactory
{
private:
public:
    VacuumMerlinEngineFactory();
    virtual ~VacuumMerlinEngineFactory();

    Component *produce();
};

#endif