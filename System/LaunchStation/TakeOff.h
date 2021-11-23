#ifndef TAKEOFF_H
#define TAKEOFF_H

/** @brief A concrete command class.

    A oncrete command class that will allow the rocket to take off.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Command.h"

class TakeOff : public Command
{
private:
public:
	/** Initializes the command with the rocket.
	 	*/ 
	TakeOff(Rocket* rocket);
	/** Default destructor.
	 	*/ 
	~TakeOff();
	/** Allows the rocket take off.
	 	*/ 
	void Execute();
};

#endif
