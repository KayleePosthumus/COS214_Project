#ifndef VACUUMMERLINENGINE_H
#define VACUUMMERLINENGINE_H

/** @brief A concrete Engine Component class.

    A class that acts as the Components to be added to the rockets.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Engine.h"

#include <string>

using namespace std;

class VacuumMerlinEngine : public Engine
{
private:
public:
        /** Initializes the name of the component.
        */
        VacuumMerlinEngine(string name);
        /** Initializes the name of the component and the successor of the component.
        */
        VacuumMerlinEngine(string name, Component *successor);
        /** Default destructor.
        */
        ~VacuumMerlinEngine();

        /** Abstract. Clones the current vacuum merlin engine component as implemented by a Prototype design pattern.
     * @return A copy of this vacuum merlin engine component.
        */
        Component *Clone();
};

#endif
