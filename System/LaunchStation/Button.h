#ifndef BUTTON_H
#define BUTTON_H

#include "Command.h"

class Button
{
private:
    Command* _takeOff;
public:
    Button(Command* t);
    ~Button();
    void TakeOff();
};

#endif