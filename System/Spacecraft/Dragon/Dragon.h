#ifndef DRAGON_H
#define DRAGON_H

#include "../SpaceCraft.h"
#include "../Payload.h"
#include "Cargo.h"

#include <vector>
#include <algorithm>

class Dragon : public Payload
{
private:
protected:
	double _maxCargoCapacity;
	double _currentCargoCapacity = 0;
	vector<Cargo*> *_cargoModules;

public:
	Dragon();
	virtual ~Dragon();
	virtual bool AddCargo(Cargo*) = 0;
	virtual bool RemoveCargo(Cargo*) = 0;
};

#endif
