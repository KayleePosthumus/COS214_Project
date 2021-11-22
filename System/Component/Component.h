#ifndef COMPONENT_H
#define COMPONENT_H

/** @brief An abstract component class.

    A class that acts as the components to be added to the rockets.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "../Settings.h"

#include <string>

using namespace std;

class Component
{
private:
	int health = 0;	  /**<Health of the current component*/
	string name = ""; /**<Name of the component*/

public:
	/** Initializes the name of the component.
        */
	Component(string name);
	/** Initializes the name of the component and the successor of the component.
        */
	Component(string name, Component *successor);
	/** Default destructor.
        */
	virtual ~Component();

	/** Decreases the health of the component
        @param damageAmount - The amount of damage that needs to be dealt to the component
        */
	virtual bool TakeDamage(int damageAmount);
	/** Decreases the health of the component by taking lift off damage.
        @param damageAmount - The amount of damage that needs to be dealt to the component by liftoff damage
        */
	virtual void TakeLiftOffDamage(int damageAmount);
	/** Abstract. Destroys the Component but does not destruct it.
        */
	virtual void Destroy() = 0;

	/** Accessor that returns the health of the component.
     * @return The health of the component.
        */
	int GetHealth();
	/** Sets the health of the component
        @param health - The new health the component should have
        */
	void SetHealth(int health);

	/** Accessor that returns the name of the component.
     * @return The name of the component.
        */
	string GetName();
	/** Sets the name of the component
        @param name - The new name the component should have
        */
	void SetName(string name);

	/** Abstract. Clones the current component as implemented by a Prototype design pattern.
     * @return A copy of this component.
        */
	virtual Component *Clone() = 0;

	Component *successor = nullptr; /**<The successor to this component for the Chain of Command Design Pattern*/
};

#endif
