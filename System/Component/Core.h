#ifndef CORE_H
#define CORE_H

#include "Component.h"
#include "../Settings.h"

using namespace std;

class Core : public Component
{
private:
public:
	Core(string name);
	Core(string name, Component *successor);
	virtual ~Core();

	virtual Component* Clone() = 0;
};

#endif