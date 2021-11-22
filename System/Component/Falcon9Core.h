#ifndef FALCON9CORE_H
#define FALCON9CORE_H

#include "Component.h"

#include "MerlinEngine.h"
#include "VacuumMerlinEngine.h"

#include <string>
#include <vector>

using namespace std;

class Falcon9Core : public Component
{
private:
	Component* _engines = 0; //Head pointer to linked list of engines
public:
	Falcon9Core(string name);
	Falcon9Core(string name, Component *successor);
	~Falcon9Core();

	void AddEngines(Component* merlinEngine);
	void AddCore(Component* core);

	void Destroy();

	Component* Clone();
};

#endif
