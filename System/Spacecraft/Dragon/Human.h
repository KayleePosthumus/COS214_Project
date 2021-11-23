#ifndef HUMAN_H
#define HUMAN_H

/** @brief A crew class.

    A class acts as one modules to add to the dragon spacecrafts.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include <string>

class Human
{
private:
	std::string _name; /**<Person name*/
public:
	/** Initializes the name of the person.
        */
	Human(std::string);

	/** Default destructor.
        */
	~Human();

	/** Setter for the person name.
	 * 	@param n - Name of the person
        */
	void SetName(std::string n);

	/** Accessor for the person name.
	 * 	@return Name of the person
        */
	std::string GetName();
};

#endif
