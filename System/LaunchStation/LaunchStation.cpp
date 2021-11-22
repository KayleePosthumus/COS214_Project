#include "LaunchStation.h"

LaunchStation* LaunchStation::launchStation = nullptr;

LaunchStation::LaunchStation() {}

LaunchStation::~LaunchStation() {
	if (launchStation)
		delete launchStation;
}

LaunchStation* LaunchStation::instance()
{
	if (!launchStation)
		launchStation = new LaunchStation();

	return launchStation;
}

void LaunchStation::setSatelliteList(StarlinkSatellite* satelliteList)
{
	launchStation->satelliteList = satelliteList;
}