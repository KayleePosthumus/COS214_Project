#ifndef LASER_H
#define LASER_H

#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "StarlinkSatellite.h"

class Laser
{
private:
	StarlinkSatellite* satelliteList;
public:
	Laser();
	Laser(StarlinkSatellite*);
	~Laser();
	void notify();
	void addSatellite(StarlinkSatellite*);
};

#endif
