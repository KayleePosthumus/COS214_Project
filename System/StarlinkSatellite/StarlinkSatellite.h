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
public:
	StarlinkSatellite();
	StarlinkSatellite(string);
	~StarlinkSatellite();
	void CommunicateSatellite();
	void CommunicateGround();
	Iterator* CreateIterator();
	Payload* Clone();
	string GetCargo();
	string GetPassengers();
};

#endif
