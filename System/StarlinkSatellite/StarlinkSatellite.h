#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

#include <string>
#include <cstdio>
#include "Iterator.h"
#include "../Spacecraft/Payload.h"

class Iterator;

using namespace std;

class StarlinkSatellite : public Payload
{
private:
	string name;
	StarlinkSatellite* nextSatellite;
public:
	StarlinkSatellite();
	StarlinkSatellite(string);
	~StarlinkSatellite();
	StarlinkSatellite* clone(StarlinkSatellite*);
	StarlinkSatellite* getNext();
	void setNext(StarlinkSatellite*);
	void communicateSatellite();
	void communicateGround();
	Iterator* createIterator();
	string getName();
};

#endif
