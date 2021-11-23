#ifndef PAYLOAD_H
#define PAYLOAD_H

/** @brief An abstract payload class.

    A class acts as the payload that will be launched on the rockets.
    @author Ctrl Alt Defeat
    @date November 2021
    */

//#include "Dragon/Modules.h"
//#include "../StarlinkSatellite/Iterator.h"

#include <string>
using namespace std;

class Iterator;

class Payload
{
private:
	string _name; /**<Name of the payload*/
protected:
	Payload *_next = 0;	/**<The next payload in the linked list*/
public:
	/** Initializes the name of the payload.
        */
	Payload(string);

	/** Default destructor.
        */
	virtual ~Payload();

	/** Accessor for the next payload.
	 * 	@return Pointer to the next payload
        */
	Payload* GetNext();

	/** Setter for the next payload.
	 * 	@param next - The next payload
        */
	void SetNext(Payload* next);

	/** Accessor for the name of the payload.
	 * 	@return The name of the payload
        */
	string GetName();

	/** Abstract. Clones the current payload.
	 * 	@return A copy of this payload
        */
	virtual Payload* Clone() = 0;

	/** Abstract. Accessor for the cargo on board.
	 * 	@return Formatted list of cargo
        */
	virtual string GetCargo() = 0;

	/** Abstract. Accessor for the crew on board.
	 * 	@return Formatted list of crew
        */
	virtual string GetPassengers() = 0;

	/** Abstract. Allows satellites to communicate to each as part of the Mediator pattern.
        */
	virtual void CommunicateSatellite() = 0;

	/** Abstract. Allows satellites to communicate with the ground.
        */
	virtual void CommunicateGround() = 0;

	/** Abstract. Creates an iterator for the linked list of payloads.
	 * 	@return New iterator
        */
	virtual Iterator* CreateIterator() = 0;
};

#endif
