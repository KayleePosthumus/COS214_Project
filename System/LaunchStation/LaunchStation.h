#ifndef LAUNCHSTATION_H
#define LAUNCHSTATION_H

/** @brief A class that runs the simulations.

    A class which uses the singleton pattern to set up and run the rocket launch simulations.
    @author Ctrl Alt Defeat
    @date November 2021
    */

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
	StarlinkSatellite *_satelliteList;	/**<The list of satellites which will be communicated with via radio signals*/
	static LaunchStation *_launchStation;	/**<Single instance of the launch station*/
	Button *launchButtons;	/**<Invoker to call the launch method*/
	vector<Rocket*> _simulations;	/**<Holds the active simulations so that they can be run in batches*/
	Observer* _observer; /**<Observes whether there are faults in the launch*/
	int rocket;	/**<Holds the type of rocket created for editing the simulation*/
	RocketCaretaker* caretaker;	/**<Caretaker to hold and restore the memento before and after static fire/launch*/

protected:
	/** Protected constrcutor to ensure only on instance.
	 	*/ 
	LaunchStation();
	/** Default destructor.
	 	*/	 
	~LaunchStation();

public:
	/** Creates and returns the one instance of the launch station.
	 * 	@return Single static instance of the launch station
	 	*/ 
	static LaunchStation* instance();

	/** Creates the satellite list
	  	@param satelliteList - The head of the satellite linked list.
	 	*/  
	void setSatelliteList(StarlinkSatellite* satelliteList);

	/** Prompts input to the user for creating a rocket simulation and adds it to the simulation vector.
	 	*/ 
	void AddSimulation();

	/** Prompts input to the user for editing a rocket simulation in the simulation vector.
	 	@param type - The type of rocket initially created
		 */ 
	void EditSimulation(int type);

	/** Handles the output for the second stage of the Dragon Spacecraft.
	 	@param d - The dragon spacecraft attempting to dock
		 */ 
	void DragonStage2(Payload* d);

	/** Handles the output for the second stage of the Crew Dragon.
	 	@param d - The dragon spacecraft attempting to dock.
		 */ 
	void CrewDragonStage2(Payload* d);

	/** Handles the output for the second stage of the Starlink Satellites.
	 	@param d - The satellites reaching low earth orbit
		 */ 
	void SatellitesStage2(Payload* d);

	/** Allows the user to create and edit simulations.
		 */ 
	void TestSimulation();

	/** Created and run the current simulations.
		 */ 
	void RunSimulations();
};

#endif
