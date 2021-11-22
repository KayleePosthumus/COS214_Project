#ifndef ROCKETMEMENTO_H
#define ROCKETMEMENTO_H

#include "RocketState.h"

#include <vector>

class RocketState;

class RocketMemento
{
private:
	RocketState* _state;

public:
	RocketMemento(string, int, vector<int>, int);
	~RocketMemento();

	RocketState* getState();
};

#endif
