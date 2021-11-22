#include "Observer.h"

Observer::Observer(Rocket* subject)
{
    _subject = subject;
}

Observer::~Observer()
{

}

void Observer::update() 
{
    _observerState = _subject->GetState();
}

bool Observer::GetObserverState()
{
    return _observerState;
}
