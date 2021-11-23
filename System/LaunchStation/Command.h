#ifndef COMMAND_H
#define COMMAND_H

/** @brief Command class.

    The abstract command class which will control the rocket commands
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "../Spacecraft/FalconRocket/FalconHeavy.h"
#include "../Stage/Stage1.h"
#include "../Stage/Stage2.h"

#include <iostream>

using namespace std;

class Command
{
protected:
	Rocket* _rocket;	/**<The current rocket on which the commands will be executed*/
public:
	/** Initializes the command with the rocket.
		*/ 
	Command(Rocket* rocket);
	/** Default virtual destructor.
	 	*/ 
	virtual ~Command();
	/** Abstract. Make requests to the rocket.
	 	*/  
	virtual void Execute() = 0;
};

#endif
