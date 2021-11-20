#ifndef STAGE2_H
#define STAGE2_H

#include "Stage.h"

class Stage2 : public Stage
{
private:
public:
	Stage2();
	~Stage2();
	void handle();
	Stage* Clone();
};

#endif
