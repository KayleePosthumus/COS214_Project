#ifndef MERLINENGINE_H
#define MERLINENGINE_H

/** @brief A concrete Engine Component class.

    A class that acts as the Components to be added to the rockets.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Engine.h"

#include <string>

using namespace std;

class MerlinEngine : public Engine
{
private:
public:
        /** Initializes the name of the component.
        */
        MerlinEngine(string name);
        /** Initializes the name of the component and the successor of the component.
        */
        MerlinEngine(string name, Component *successor);
        /** Default destructor.
        */
        ~MerlinEngine();

        /** Abstract. Clones the current merlin engine component as implemented by a Prototype design pattern.
     * @return A copy of this merlin engine component.
        */
        Component *Clone();
};

#endif