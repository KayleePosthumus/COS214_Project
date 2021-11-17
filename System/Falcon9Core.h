#ifndef FALCON9CORE_H
#define FALCON9CORE_H

#include "Core.h"

#include <string>

using namespace std;

class Falcon9Core : public Core
{
private:
public:
	Falcon9Core(string name);
	~Falcon9Core();

	void Destroy();
};

#endif
