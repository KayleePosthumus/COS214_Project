#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

#include <string>
#include <cstdio>
#include "Iterator.h"

class StarlinkSatellite
{
private:
	std::string name;
	StarlinkSatellite* next;
public:
	StarlinkSatellite();
	StarlinkSatellite(std::string);
	~StarlinkSatellite();
	StarlinkSatellite* clone(StarlinkSatellite*);
	StarlinkSatellite* getNext();
	void communicateSatellite();
	void communicateGround();
	Iterator* createIterator();
	std::string getName();
};

#endif
