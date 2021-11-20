#ifndef ITERATOR_H
#define ITERATOR_H

#include "StarlinkSatellite.h"
class StarlinkSatellite;

class Iterator
{
private:
	StarlinkSatellite* first;
	StarlinkSatellite* current;
public:
	Iterator();
	Iterator(StarlinkSatellite*);
	~Iterator();
	StarlinkSatellite* firstItem();
	StarlinkSatellite* nextItem();
	StarlinkSatellite* currentItem();
	bool isDone();
	bool isLast();
	void reset();
};

#endif
