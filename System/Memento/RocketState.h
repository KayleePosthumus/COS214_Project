#ifndef ROCKETSTATE_H
#define ROCKETSTATE_H

/** @brief A rocket state class.

    A class that holds the current state of the objects members.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "../Component/Component.h"
#include "../Stage/Stage.h"
#include "../Spacecraft/Payload.h"
#include "../Spacecraft/Observer.h"

#include <string>
#include <vector>

using namespace std;

class RocketState
{
private:
    string _name; /**<Name of the rocket*/
    int _rocketHealth; /**<Rocket health*/
    vector<int> _coreHealth; /**<Vector of all the cores' health*/
    int _vacuumHealth; /**<Vacuum merlin health*/
    Stage* _subjectStage; /**Current launch stage*/

public:
    /** Initializes the name, health, core health and vacuum health.
        */
    RocketState(string, int, vector<int>, int);

    /** Default destructor.
        */
    ~RocketState();

    /** Accessor for the health.
	 * 	@return Health of the rocket
        */
    int GetHealth();

    /** Accessor for the name.
	 * 	@return Name of the rocket
        */
    string GetName();

    /** Accessor for the core health.
	 * 	@return Health of all the cores
        */
    vector<int> GetCoreHealth();

    /** Accessor for the vacuum merlin health.
	 * 	@return Health of the vacuum merlin
        */
    int GetVacuumHealth();

    /** Accessor for the stage.
	 * 	@return Current launch stage of the rocket
        */
    Stage* GetStage();
};

#endif