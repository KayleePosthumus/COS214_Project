#ifndef ROCKETMEMENTO_H
#define ROCKETMEMENTO_H

/** @brief A rocket memento class.

    A class that holds a reference to the current state of the rocket.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "RocketState.h"

#include <vector>

class RocketState;

class RocketMemento
{
private:
	RocketState* _state; /**<Pointer to current state of rocket*/

public:
	/** Initializes the name, health, core health and vacuum health.
        */
	RocketMemento(string, int, vector<int>, int);

	/** Default destructor.
        */
	~RocketMemento();

	/** Accessor for the state.
	 * 	@return State of the rocket
        */
	RocketState* getState();
};

#endif
