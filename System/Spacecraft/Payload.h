#ifndef PAYLOAD_H
#define PAYLOAD_H

//#include "Dragon/Modules.h"
//#include "../StarlinkSatellite/Iterator.h"

#include <string>
using namespace std;

class Iterator;

class Payload
{
private:
	string _name;
protected:
	Payload *_next = 0;
public:
	Payload(string);
	virtual ~Payload();

	Payload* GetNext();
	void SetNext(Payload*);

	string GetName();

	virtual Payload* Clone() = 0;
	virtual string GetCargo() = 0;
	virtual string GetPassengers() = 0;
	virtual void CommunicateSatellite() = 0;
	virtual void CommunicateGround() = 0;
	virtual Iterator* CreateIterator() = 0;
};

#endif
