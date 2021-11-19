#include "Laser.h"

Laser::Laser()
	: satelliteList(nullptr)
{
}

Laser::~Laser()
{
	if (!satelliteList)
		return;

	Iterator *it = satelliteList->createIterator();
	StarlinkSatellite* current = nullptr;
	while (!it->isDone())
	{
		current = it->currentItem();
		it->nextItem();
		delete current;
	}
}

Laser::Laser(StarlinkSatellite *satellitelist)
	: satelliteList(satelliteList)
{
}

void Laser::notify()
{
	if (!satelliteList)
		return;

	Iterator *it = satelliteList->createIterator();
	while (!it->isDone())
	{
		it->currentItem()->communicateSatellite();
		it->nextItem();
	}

	printf("\n");
}

void Laser::addSatellite(StarlinkSatellite *satellite)
{
	if (!satelliteList) {
		satelliteList = satellite;
		return;
	}

	Iterator* it = satelliteList->createIterator();
	StarlinkSatellite* lastSat = satelliteList;

	while (!it->isDone()) {
		lastSat = it->nextItem();
	}

	lastSat->setNext(satellite);
}