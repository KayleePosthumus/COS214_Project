#ifndef MERLINENGINEFACTORY_H
#define MERLINENGINEFACTORY_H

#include "ComponentFactory.h"
#include "MerlinEngine.h"

class MerlinEngineFactory : public ComponentFactory
{
private:
public:
    MerlinEngineFactory();
    virtual ~MerlinEngineFactory();

    Component *produce();
};

#endif
