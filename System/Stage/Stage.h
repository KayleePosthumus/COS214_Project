#ifndef STAGE_H
#define STAGE_H

class Stage
{
private:
public:
	Stage();
	~Stage();
	virtual void handle();
	virtual Stage* Clone();
};

#endif
