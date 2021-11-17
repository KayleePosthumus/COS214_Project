#include "CoreFactory.h"

CoreFactory::CoreFactory() {}
CoreFactory::~CoreFactory() {}

Component *CoreFactory::produce()
{
    return new Falcon9Core("Falcon9Core");
};
