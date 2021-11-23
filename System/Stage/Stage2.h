#ifndef STAGE2_H
#define STAGE2_H

/** @brief A concrete stage class.

    A class acts as the second of the launch stages.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Stage.h"

class Stage2 : public Stage
{
private:
public:
	/** Default constructor.
        */
	Stage2();

	/** Default destructor.
        */
	~Stage2();

	/** Prints the details of the state.
        */
	void handle();
};

#endif
