#ifndef STAGE_H
#define STAGE_H

#include <iostream>

using namespace std;

class Stage
{
private:
public:
	Stage();
	virtual ~Stage();
	virtual void handle();
};

#endif
