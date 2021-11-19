#ifndef ITERATOR_H
#define ITERATOR_H

#include "StarlinkSatellite.h"

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
	bool isDone();
	StarlinkSatellite* currentItem();
};

#endif
