#ifndef FALCON9_H
#define FALCON9_H

#include "Rocket.h"

#include <string>

using namespace std;

class Falcon9 : public Rocket
{
private:
	Stage* subjectStage;

public:
	Falcon9(string name);
	~Falcon9();

	Stage* getStage();
	void setStage(Stage* stage);
};

#endif
