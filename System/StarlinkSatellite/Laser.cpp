#include "Laser.h"

Laser::Laser()
	: satelliteList(nullptr)
{
}

Laser::~Laser()
{
	/*if (!satelliteList)
		return;

	Iterator *it = satelliteList->CreateIterator();
	Payload* current = nullptr;
	while (!it->isDone())
	{
		current = it->currentItem();
		it->nextItem();
		delete current;
	}*/
}

Laser::Laser(Payload *newSatelliteList)
	: satelliteList(newSatelliteList)
{
}

void Laser::notify()
{
	if (!satelliteList)
		return;

	Iterator *it = satelliteList->CreateIterator();
	while (!it->isLast())
	{
		((StarlinkSatellite*) it->currentItem())->CommunicateSatellite();
		printf(" pinging --> ");
		it->nextItem();
	}

	((StarlinkSatellite*) it->currentItem())->CommunicateSatellite();
	printf("\n");

	delete it;
}

void Laser::addSatellite(Payload *satellite)
{
	if (!satelliteList) {
		satelliteList = satellite;
		return;
	}

	Iterator* it = satelliteList->CreateIterator();
	Payload* lastSat = satelliteList;

	while (!it->isLast()) {
		lastSat = it->nextItem();
	}

	lastSat->SetNext(satellite);
}