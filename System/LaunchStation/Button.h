#ifndef BUTTON_H
#define BUTTON_H

/** @brief Button class.

    A class that acts as the invoker for the command pattern.
    @author Ctrl Alt Defeat
    @date November 2021
    */

#include "Command.h"

class Button
{
private:
    Command* _takeOff; /**<The command that will be executed*/
public:
    /** Initializes the button with the command.
        */
    Button(Command* t);
    /** Default destructor.
        */ 
    ~Button();
    /** Will call the commands execute method.
        */ 
    void TakeOff();
};

#endif