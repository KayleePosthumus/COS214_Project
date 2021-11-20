#ifndef ROCKETMEMENTO_H
#define ROCKETMEMENTO_H

#include "RocketState.h"

class RocketMemento
{
private:
	RocketState* _state;

public:
	RocketMemento(string, int, Component*, Stage*);
	~RocketMemento();

	RocketState* getState();
};

#endif
