#ifndef LASER_H
#define LASER_H

#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "StarlinkSatellite.h"

class Laser
{
private:
	Payload* satelliteList;
public:
	Laser();
	Laser(Payload*);
	~Laser();
	void notify();
	void addSatellite(Payload*);
};

#endif
