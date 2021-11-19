#ifndef FALCONHEAVY_H
#define FALCONHEAVY_H

#include "Rocket.h"

#include <string>

using namespace std;

class FalconHeavy : public Rocket
{
private:
	Stage* subjectStage;

public:
	FalconHeavy(string name);
	~FalconHeavy();

	Stage* getStage();
	void setStage(Stage* stage);
};

#endif
