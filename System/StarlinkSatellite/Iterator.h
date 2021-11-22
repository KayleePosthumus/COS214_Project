#ifndef ITERATOR_H
#define ITERATOR_H

//#include "StarlinkSatellite.h"
#include "../Spacecraft/Payload.h"

//class StarlinkSatellite;
//class Payload;

class Iterator
{
private:
	Payload* first;
	Payload* current;
public:
	Iterator();
	Iterator(Payload*);
	~Iterator();
	Payload* firstItem();
	Payload* nextItem();
	Payload* currentItem();
	bool isDone();
	bool isLast();
	void reset();
};

#endif
