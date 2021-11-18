#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "Factory.h"
#include "../Component/Component.h"

class ComponentFactory : public Factory
{
private:
public:
	ComponentFactory();
	virtual ~ComponentFactory();

	virtual Component *produce() = 0;
};

#endif
