#ifndef TAKEOFF_H
#define TAKEOFF_H

#include "Command.h"

class TakeOff : public Command
{
private:
public:
	TakeOff(Rocket* rocket);
	~TakeOff();

	void Execute();
};

#endif
