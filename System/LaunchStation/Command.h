#ifndef COMMAND_H
#define COMMAND_H

#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "../Spacecraft/FalconRocket/FalconHeavy.h"
#include "../Stage/Stage1.h"
#include "../Stage/Stage2.h"

#include <iostream>

using namespace std;

class Command
{
protected:
	Rocket* _rocket;
public:
	Command(Rocket* rocket);
	virtual ~Command();

	virtual void Execute() = 0;
};

#endif
