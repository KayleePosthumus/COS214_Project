#ifndef CREWDRAGON_H
#define CREWDRAGON_H

#include "Dragon.h"
#include "Human.h"

class CrewDragon : public Dragon
{
private:
	vector<Human*> _crewMembers;
	size_t _maxCrew = 7;

public:
	CrewDragon(string name);
	~CrewDragon();
	bool AddCargo(Cargo*);
	bool RemoveCargo(Cargo*);
	bool AddCrew(Human*);
	bool RemoveCrew(Human*);
	Payload* Clone();
	string GetPassengers();
};

#endif
