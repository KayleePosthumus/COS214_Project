#ifndef ENGINE_H
#define ENGINE_H

/** @brief An abstract engine component class.

    A class that acts as the engine components to be added to the rockets.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Component.h"
#include "Settings.h"

#include <string>

using namespace std;

class Engine : public Component
{
private:
public:
        /** Initializes the name of the engine component.
        */
        Engine(string name);
        /** Initializes the name of the engine component and the successor of the engine component.
        */
        Engine(string name, Component *successor);
        /** Default destructor.
        */
        ~Engine();

        /** Destroys the engine component but does not destruct it.
        */
        void Destroy();

        /** Abstract. Clones the current engine component as implemented by a Prototype design pattern.
         * @return A copy of this engine component.
        */
        virtual Component *Clone() = 0;
};

#endif