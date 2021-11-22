#ifndef DRAGONSPACECRAFT_H
#define DRAGONSPACECRAFT_H

#include "Dragon.h"

class DragonSpacecraft : public Dragon
{
private:
public:
	DragonSpacecraft(string name);
	~DragonSpacecraft();
	bool AddCargo(Cargo*);
	bool RemoveCargo(Cargo*);
	Payload* Clone();
	string GetPassengers();
};

#endif
