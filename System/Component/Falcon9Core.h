#ifndef FALCON9CORE_H
#define FALCON9CORE_H

#include "Core.h"

#include <string>

using namespace std;

class Falcon9Core : public Component
{
private:
public:
	Falcon9Core(string name);
	Falcon9Core(string name, Component *successor);
	~Falcon9Core();

	void Destroy();
	void TransitionIntoStageTwo(Component *prev);
};

#endif
