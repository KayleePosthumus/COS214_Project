#include "VacuumMerlinEngineFactory.h"

VacuumMerlinEngineFactory::VacuumMerlinEngineFactory() {}
VacuumMerlinEngineFactory::~VacuumMerlinEngineFactory() {}

Component *VacuumMerlinEngineFactory::produce()
{
    return new VacuumMerlinEngine("VacuumMerlinEngine");
};
