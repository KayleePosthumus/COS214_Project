#ifndef FALCON9_H
#define FALCON9_H

/** @brief A concrete rocket class.

    A class that is one of the possible rockets.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Rocket.h"

#include <string>

using namespace std;

class Falcon9 : public Rocket
{
private:
	bool _state = true; /**<Whether launch was successful*/
public:
	/** Initializes the name of the rocket.
        */
	Falcon9(string name);

	/** Default destructor.
        */
	~Falcon9();

	/** Accessor for the rocket health percentage. Primitive operation for Template Method
     *  @return Rocket health as a percentage
        */
	float GetHealthPercentage();

	/** Decreases the health of the component by taking lift off damage.
        */
	void TakeLiftOffDamage();

	/** Accessor for the state of the rocket launch.
        @return The current state of the rocket launch
        */
	bool GetState();
};

#endif
