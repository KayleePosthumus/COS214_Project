#include "StarlinkSatellite.h"

StarlinkSatellite::StarlinkSatellite() : Payload("Default Name")
{
}

StarlinkSatellite::StarlinkSatellite(string name) : Payload(name)
{
}

StarlinkSatellite::~StarlinkSatellite()
{
}

void StarlinkSatellite::CommunicateSatellite()
{
	printf("%s", GetName().c_str());
}

void StarlinkSatellite::CommunicateGround()
{
	printf("%s Sending signals to the ground\n", GetName().c_str());
}

Iterator *StarlinkSatellite::CreateIterator()
{
	return new Iterator(this);
}

Payload* StarlinkSatellite::Clone()
{
	Payload* c = new StarlinkSatellite(GetName());
	return c;
}

string StarlinkSatellite::GetCargo()
{
	return "";
}

string StarlinkSatellite::GetPassengers()
{
	return "";
}