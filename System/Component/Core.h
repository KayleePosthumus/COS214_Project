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
	virtual ~Core();
};

#endif