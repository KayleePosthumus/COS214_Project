#ifndef OBSERVER_H
#define OBSERVER_H

#include "FalconRocket/Rocket.h"

class Rocket;
class Observer
{
private:
	Rocket* _subject;
	bool _observerState;
public:
	Observer(Rocket* subject);
	~Observer();
	void update();
	bool GetObserverState();
};

#endif
