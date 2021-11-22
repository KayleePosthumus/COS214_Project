#include "Button.h"

Button::Button(Command* t)
{
    _takeOff = t;
}

Button::~Button()
{
    delete _takeOff;
}

void Button::TakeOff()
{
    _takeOff->Execute();
}