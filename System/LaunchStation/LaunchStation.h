#ifndef LAUNCHSTATION_H
#define LAUNCHSTATION_H

#include "../StarlinkSatellite/StarlinkSatellite.h"

class LaunchStation
{
private:
	StarlinkSatellite* satelliteList;
	static LaunchStation* launchStation;
protected:
	LaunchStation();
	~LaunchStation();
public:
	static LaunchStation* instance();
	void setSatelliteList(StarlinkSatellite*);
};

#endif
