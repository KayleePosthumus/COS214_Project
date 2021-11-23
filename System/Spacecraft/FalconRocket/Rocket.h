#ifndef Rocket_H
#define Rocket_H

/** @brief An abstract rocket class.

    A class acts as the parent to rocket classes.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "../../Component/Component.h"
#include "../Payload.h"
#include "../Observer.h"
#include "../../Stage/Stage.h"
#include "../../Memento/RocketMemento.h"
#include "../../Memento/RocketState.h"
#include "../../Settings.h"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Observer;
class RocketMemento;
using namespace std;

class Rocket
{
private:
    string _name; /**<Name of the rocket*/
    int _health = 0; /**<Rocket health*/

    Component *_falcon9Cores = 0; /**<Linked list of cores*/
    Component *_vacuumMerlin; /**<VacuumMerlin*/
    Payload *_payload; /**<Linked list of payloads*/
    vector<Observer*> _observerList; /**<Vector of observers*/

protected:
    Stage* _subjectStage = 0; /**<The current stage of the launch*/

public:
    /** Initializes the name of the rocket.
        */
    Rocket(string name);

    /** Default destructor.
        */
    virtual ~Rocket();

    /** Adds cores to the linked list.
     *  @param cores - Next core to be added
        */
    void AddCores(Component *cores);

    /** Adds vacuum merlin to the rocket.
     *  @param vacuum - Vacuum merlin to be added
        */
    void AddVacuum(Component *vacuum);

    /** Adds payload to the rocket.
     *  @param payload - Payload to be added
        */
    void SetPayload(Payload *payload);

    /** Damages the cores and engines randomly during launch.
        */
    virtual void TakeLiftOffDamage();

    /** Accessor for the rocket name.
     *  @return Name of the rocket
        */
    string GetName();

    /** Accessor for the rocket health.
     *  @return Health of the rocket
        */
    int GetHealth();

    /** Sets the health of the rocket.
     *  @param h - New health
        */
    void SetHealth(int h);

    /** Accessor for the rocket cores.
     *  @return Formatted list of cores
        */
    string GetCores();

    /** Accessor for the rocket cores list.
     *  @return Head of the cores list
        */
    Component* GetCoreList();

    /** Accessor for the vacuum merlin health.
     *  @return Health of the vacuum merlin
        */
    int GetMerlinHealth();

    /** Accessor for the payload name.
     *  @return Name of the payload
        */
    string GetPayloadName();

    /** Accessor for the payload.
     *  @return Payload on the rocket
        */
    Payload* GetPayload();

    /** Prints the details of the rocket including the name and health of components. Template method
        */
    void PrintDetails();

    /** Abstract. Accessor for the rocket health percentage. Primitive operation for Template Method
     *  @return Rocket health as a percentage
        */
    virtual float GetHealthPercentage() = 0;

    /** Adds an observer to the rocket.
     *  @param o - Observer to be added
        */
    void attach(Observer* o);

    /** Removes an observer from the rocket.
     *  @param o - Observer to be removed
        */
    void detach(Observer* o);

    /** Notifies observers of change of state.
        */
    void notify(); 

    /** Prints details of current state.
        */
    void PrintStage();

    /** Abstract. Accessor for the rocket state.
     *  @return State of the rocket
        */
    virtual bool GetState() = 0;

    /** Abstract. Accessor for the rocket stage.
     *  @return Stage of the rocket
        */
    Stage* getStage();

    /** Changes the stage of the rocket.
     *  @param stage - New stage
        */
	void SetStage(Stage* stage);   
    
    /** Restore the rocket to it's original health.
     *  @param mem - Memento used to restore the rocket state
        */
    void restoreMemento(RocketMemento* mem);

    /** Creates memento at the current state.
     *  @return Memento that holds the current state
        */
    RocketMemento* createMemento();
};

#endif