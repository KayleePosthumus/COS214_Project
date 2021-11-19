#ifndef DRAGONSPACECRAFT_H
#define DRAGONSPACECRAFT_H

#include "Dragon.h"

class DragonSpacecraft : public Dragon
{
private:
public:
	DragonSpacecraft();
	~DragonSpacecraft();
	bool AddCargo(Cargo*);
	bool RemoveCargo(Cargo*);
};

#endif
