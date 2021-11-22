#ifndef FALCONHEAVY_H
#define FALCONHEAVY_H

#include "Rocket.h"

#include <string>

using namespace std;

class FalconHeavy : public Rocket
{
private:
	bool _state = true;
public:
	FalconHeavy(string name);
	~FalconHeavy();
	float GetHealthPercentage();
	void TakeLiftOffDamage();
	bool GetState();
};

#endif
