#ifndef DRAGONSPACECRAFT_H
#define DRAGONSPACECRAFT_H

/** @brief A concrete dragon class.

    A class acts as one of the dragon spacecrafts.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Dragon.h"

class DragonSpacecraft : public Dragon
{
private:
public:
	/** Initializes the name of the dragon.
        */
	DragonSpacecraft(string name);

	/** Default destructor.
        */
	~DragonSpacecraft();

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
