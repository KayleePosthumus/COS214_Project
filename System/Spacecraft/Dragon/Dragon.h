#ifndef DRAGON_H
#define DRAGON_H

/** @brief An abstract dragon class.

    A class acts as the parent to the different type of Dragon spacecrafts.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "../Payload.h"
#include "Cargo.h"
#include "../../StarlinkSatellite/Iterator.h"

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Dragon : public Payload
{
protected:
	double _maxCargoCapacity; /**<Max amount of cargo*/
	double _currentCargoCapacity = 0;	/**<Current amount of cargo*/
	vector<Cargo*> _cargoModules;	/**Vector of cargo*/

public:
	/** Initializes the name of the dragon.
        */
	Dragon(string name);

	/** Default destructor.
        */
	virtual ~Dragon();

	/** Abstract. Add cargo to the dragon.
	 * 	@param c - Cargo to be added
	 * 	@return Success or failure of adding the cargo
        */
	virtual bool AddCargo(Cargo* c) = 0;

	/** Abstract. Remove cargo from the dragon.
	 * 	@param c - Cargo to be removed
	 * 	@return Success or failure of removing the cargo
        */
	virtual bool RemoveCargo(Cargo* c) = 0;

	/** Abstract. Clones the current dragon.
	 * 	@return A copy of this dragon
        */
	virtual Payload* Clone() = 0;

	/** Accessor for the cargo on board.
	 * 	@return Formatted list of cargo
        */
	string GetCargo();

	/** Abstract. Accessor for the crew on board.
	 * 	@return Formatted list of crew
        */
	virtual string GetPassengers() = 0;

	/** Allows satellites to communicate to each as part of the Mediator pattern.
        */
	void CommunicateSatellite();

	/** Allows satellites to communicate with the ground.
        */
	void CommunicateGround();

	/** Creates an iterator for the linked list of payloads.
	 * 	@return New iterator
        */
	Iterator* CreateIterator();
};

#endif
