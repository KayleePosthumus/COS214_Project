#ifndef ROCKETCARETAKER_H
#define ROCKETCARETAKER_H

#include "RocketMemento.h"

class RocketCaretaker
{
private:
	RocketMemento* _mem;

public:
	RocketCaretaker();
	~RocketCaretaker();

	void setMemento(RocketMemento*);
	RocketMemento* getMemento();
};

#endif
