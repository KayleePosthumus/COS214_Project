#ifndef STAGE1_H
#define STAGE1_H

/** @brief A concrete stage class.

    A class acts as the first of the launch stages.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Stage.h"

class Stage1 : public Stage
{
public:
	/** Default constructor.
        */
	Stage1();

	/** Default destructor.
        */
	~Stage1();

	/** Prints the details of the state.
        */
	void handle();
};

#endif
