#ifndef CREWDRAGON_H
#define CREWDRAGON_H

/** @brief A concrete dragon class.

    A class acts as one of the dragon spacecrafts.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Dragon.h"
#include "Human.h"

class CrewDragon : public Dragon
{
private:
	vector<Human*> _crewMembers; /**<Vector of crew*/
	size_t _maxCrew = 7; /**<Max amount of crew*/

public:
	/** Initializes the name of the dragon.
        */
	CrewDragon(string name);

	/** Default destructor.
        */
	~CrewDragon();

	/** Add cargo to the dragon.
	 * 	@param c - Cargo to be added
	 * 	@return Success or failure of adding the cargo
        */
	bool AddCargo(Cargo* c);

	/** Remove cargo from the dragon.
	 * 	@param c - Cargo to be removed
	 * 	@return Success or failure of removing the cargo
        */
	bool RemoveCargo(Cargo* c);

	/** Add crew to the dragon.
	 * 	@param h - Person to be added
	 * 	@return Success or failure of adding the person
        */
	bool AddCrew(Human* h);

	/** Remove crew from the dragon.
	 * 	@param c - Person to be removed
	 * 	@return Success or failure of removing the person
        */
	bool RemoveCrew(Human* h);

	/** Clones the current dragon.
	 * 	@return A copy of this dragon
        */
	Payload* Clone();

	/** Abstract. Accessor for the crew on board.
	 * 	@return Formatted list of crew
        */
	string GetPassengers();
};

#endif
