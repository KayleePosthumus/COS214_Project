#include "StarlinkSatellite.h"

StarlinkSatellite::StarlinkSatellite()
{
	name = "No name";
	nextSatellite = nullptr;
}

StarlinkSatellite::StarlinkSatellite(string name)
{
	this->name = name;
	nextSatellite = nullptr;
}

StarlinkSatellite::~StarlinkSatellite() {}

StarlinkSatellite *StarlinkSatellite::clone(StarlinkSatellite *original)
{
	StarlinkSatellite *copy = new StarlinkSatellite(original->name);
	copy->nextSatellite = original->nextSatellite;
	return copy;
}

StarlinkSatellite *StarlinkSatellite::getNext()
{
	if (nextSatellite)
		return nextSatellite;
	else
		return nullptr;
}

StarlinkSatellite * StarlinkSatellite::setNext(StarlinkSatellite *satellite)
{
	nextSatellite = satellite;
}

string StarlinkSatellite::getName()
{
	return name;
}

void StarlinkSatellite::communicateSatellite()
{
	printf("%s pinging -> ", name.c_str());
}

void StarlinkSatellite::communicateGround()
{
	printf("%s Testing communication with ground\n", name.c_str());
}

Iterator *StarlinkSatellite::createIterator()
{
	return new Iterator(this);
}