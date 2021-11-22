#ifndef LAUNCHSTATION_H
#define LAUNCHSTATION_H

#include "../StarlinkSatellite/StarlinkSatellite.h"

#include "../Builder/RocketBuilder.h"
#include "../Builder/Falcon9Builder.h"
#include "../Builder/FalconHeavyBuilder.h"

#include "TakeOff.h"
#include "Button.h"

#include "../Spacecraft/Observer.h"

#include "../StarlinkSatellite/Laser.h"

#include "../Memento/RocketCaretaker.h"

#include <iostream>
#include <iomanip>

using namespace std;

class LaunchStation
{
private:
	StarlinkSatellite *_satelliteList;
	static LaunchStation *_launchStation;
	Button *launchButtons;
	vector<Rocket*> _simulations;
	Observer* _observer;
	int rocket;
	RocketCaretaker* caretaker;

protected:
	LaunchStation();
	~LaunchStation();

public:
	static LaunchStation* instance();
	void setSatelliteList(StarlinkSatellite*);

	void AddSimulation();
	void EditSimulation(int);
	void DragonStage2(Payload* d);
	void CrewDragonStage2(Payload* d);
	void SatellitesStage2(Payload* d);
	void TestSimulation();
	void RunSimulations();
};

#endif
