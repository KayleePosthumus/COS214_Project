#include "LaunchStation.h"

LaunchStation::LaunchStation() {}

LaunchStation::~LaunchStation() {
	delete LaunchStation::launchStation;
}

LaunchStation* LaunchStation::instance()
{
	if (!LaunchStation::launchStation)
		launchStation = new LaunchStation();

	return launchStation;
}

void LaunchStation::setSatelliteList(StarlinkSatellite* satelliteList)
{
	LaunchStation::launchStation->satelliteList = satelliteList;
}