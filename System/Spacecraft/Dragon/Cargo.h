#ifndef CARGO_H
#define CARGO_H

/** @brief A cargo class.

    A class acts as one modules to add to the dragon spacecrafts.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include <string>

class Cargo
{
private:
	std::string _description; /**<Description of the cargo*/
    double _weight; /**<Weight of the cargo*/
public:
	/** Initializes the description and weight of the cargo.
        */
	Cargo(std::string, double);

	/** Default destructor.
        */
	~Cargo();

	/** Setter for the cargo description.
	 * 	@param d - Description of cargo
        */
	void SetDescription(std::string d);

	/** Setter for the cargo weight.
	 * 	@param w - weight of cargo
        */
	void SetWeight(double w);

	/** Accessor for the cargo description.
	 * 	@return Description of cargo
        */
    std::string GetDescription();

	/** Accessor for the cargo weight.
	 * 	@return Weight of cargo
        */
    double GetWeight();
};

#endif
