#ifndef OBSERVER_H
#define OBSERVER_H

/** @brief An observer class.

    A class that observes the launches and notifies the user of faults.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "FalconRocket/Rocket.h"

class Rocket;
class Observer
{
private:
	Rocket* _subject;	/**<The current rocket being watched*/
	bool _observerState;	/**<The current state of the observer*/
public:
	/** Initializes the observer with the rocket.
	 	*/ 
	Observer(Rocket* subject);

	/** Default destructor.
	 	*/ 
	~Observer();

	/** Updates the observer state.
	 	*/ 
	void update();

	/** Accessor for the observer state.
	 * 	@return The current obsever state
	 	*/ 
	bool GetObserverState();
};

#endif
