#ifndef VACUUMMERLINENGINEFACTORY_H
#define VACUUMMERLINENGINEFACTORY_H

#include "ComponentFactory.h"
#include "VacuumMerlinEngine.h"

class VacuumMerlinEngineFactory : public ComponentFactory
{
private:
public:
    VacuumMerlinEngineFactory();
    virtual ~VacuumMerlinEngineFactory();

    Component *produce();
};

#endif