#ifndef MERLINENGINE_H
#define MERLINENGINE_H

#include "Engine.h"

#include <string>

using namespace std;

class MerlinEngine : public Engine
{
private:
public:
	MerlinEngine(string name);
	MerlinEngine(string name, Component *successor);
	~MerlinEngine();
};

#endif