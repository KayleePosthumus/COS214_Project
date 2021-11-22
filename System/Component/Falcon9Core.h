#ifndef FALCON9CORE_H
#define FALCON9CORE_H

/** @brief A concrete component class.

    A class that acts as the components to be added to the rockets.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Component.h"

#include "MerlinEngine.h"
#include "VacuumMerlinEngine.h"

#include <string>
#include <vector>

using namespace std;

class Falcon9Core : public Component
{
private:
	Component *_engines = 0; /**<Head pointer of the engines linked list*/
public:
	/** Initializes the name of the component.
        */
	Falcon9Core(string name);
	/** Initializes the name of the component and the successor of the component.
        */
	Falcon9Core(string name, Component *successor);
	/** Default destructor.
        */
	~Falcon9Core();

	/** Adds Merlin Engines to the Core.
        @param merlinEngine - The Merlin Engines to be added to the Core.
        */
	void AddEngines(Component *merlinEngine);
	/** Adds a Core.
        @param core - The Core to add to the merlin engines.
        */
	void AddCore(Component *core);

	/** Destroys the core component but does not destruct it.
        */
	void Destroy();

	/** Abstract. Clones the current core component as implemented by a Prototype design pattern.
     * @return A copy of this core component.
    */
	Component *Clone();
};

#endif
