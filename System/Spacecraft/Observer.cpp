#include "Observer.h"

Observer::Observer()
{
    this->subject = nullptr;
    this->observerState = nullptr;
}

Observer::Observer(Rocket* s, Stage* os) 
{
    this->subject = s;
    this->observerState = os;
}
Observer::~Observer()
{

}

void Observer::update() 
{
    this->observerState = subject->getStage();
    this->observerState->handle();
}
