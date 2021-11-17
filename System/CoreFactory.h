#ifndef COREFACTORY_H
#define COREFACTORY_H

#include "ComponentFactory.h"
#include "Falcon9Core.h"

class CoreFactory : public ComponentFactory
{
private:
public:
	CoreFactory();
	virtual ~CoreFactory();

	Component *produce();
	void Destroy();
};

#endif
