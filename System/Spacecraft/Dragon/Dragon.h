#ifndef DRAGON_H
#define DRAGON_H

#include "../Payload.h"
#include "Cargo.h"
#include "../../StarlinkSatellite/Iterator.h"

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Dragon : public Payload
{
protected:
	double _maxCargoCapacity;
	double _currentCargoCapacity = 0;
	vector<Cargo*> _cargoModules;

public:
	Dragon(string name);
	virtual ~Dragon();
	virtual bool AddCargo(Cargo*) = 0;
	virtual bool RemoveCargo(Cargo*) = 0;
	virtual Payload* Clone() = 0;
	string GetCargo();
	virtual string GetPassengers() = 0;
	void CommunicateSatellite();
	void CommunicateGround();
	Iterator* CreateIterator();
};

#endif
