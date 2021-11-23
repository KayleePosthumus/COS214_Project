#ifndef ROCKETCARETAKER_H
#define ROCKETCARETAKER_H

/** @brief A rocket caretaker class.

    A class that holds a reference to the rocket memento.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "RocketMemento.h"

class RocketCaretaker
{
private:
	RocketMemento* _mem; /**<Pointer to rocket memento*/

public:
	/** Default constructor.
        */
	RocketCaretaker();

	/** Default destructor.
        */
	~RocketCaretaker();

	/** Setter for the rocket memento.
	 * 	@param m - Memento to be set
        */
	void setMemento(RocketMemento* m);

	/** Accessor for the memento.
	 * 	@return Memento of the rocket
        */
	RocketMemento* getMemento();
};

#endif
