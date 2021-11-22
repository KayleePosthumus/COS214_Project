#include "StarlinkSatellite.h"

StarlinkSatellite::StarlinkSatellite()
	: name("No name"), nextSatellite(nullptr)
{
}

StarlinkSatellite::StarlinkSatellite(string name)
	: name(name), nextSatellite(nullptr)
{
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
	return nextSatellite;
}

void StarlinkSatellite::setNext(StarlinkSatellite *satellite)
{
	nextSatellite = satellite;
}

string StarlinkSatellite::getName()
{
	return name;
}

void StarlinkSatellite::communicateSatellite()
{
	printf("%s pinged", name.c_str());
}

void StarlinkSatellite::communicateGround()
{
	printf("%s sending signals to the ground.\n", name.c_str());
}

Iterator *StarlinkSatellite::createIterator()
{
	return new Iterator(this);
}