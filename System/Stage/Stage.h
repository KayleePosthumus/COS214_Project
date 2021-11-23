#ifndef STAGE_H
#define STAGE_H

/** @brief An abstract stage class.

    A class acts as the parent class for the different launch stages.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include <iostream>

using namespace std;

class Stage
{
private:
public:
	/** Default constructor.
        */
	Stage();

	/** Default destructor.
        */
	virtual ~Stage();

	/** Prints the details of the state.
        */
	virtual void handle();
};

#endif
