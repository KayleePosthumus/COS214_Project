#ifndef VACUUMMERLINENGINE_H
#define VACUUMMERLINENGINE_H

#include "Engine.h"

#include <string>

using namespace std;

class VacuumMerlinEngine : public Engine
{
private:
public:
	VacuumMerlinEngine(string name);
	VacuumMerlinEngine(string name, Component *successor);
	~VacuumMerlinEngine();
};

#endif
