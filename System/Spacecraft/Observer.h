#ifndef OBSERVER_H
#define OBSERVER_H

#include "FalconRocket/Rocket.h"
#include "../Stage/Stage.h"
class Rocket;
class Observer
{
private:
	Rocket* subject;
	Stage* observerState;
public:
	Observer();
	Observer(Rocket* s, Stage* os);
	~Observer();
	void update();
};

#endif
