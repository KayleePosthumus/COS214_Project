#include "MerlinEngineFactory.h"

MerlinEngineFactory::MerlinEngineFactory() {}
MerlinEngineFactory::~MerlinEngineFactory() {}

Component *MerlinEngineFactory::produce()
{
    return new MerlinEngine("MerlinEngine");
};
