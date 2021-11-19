#include "Laser.h"

Laser::Laser()
{}

Laser::~Laser()
{}

Laser::Laser(StarlinkSatellite * satellitelist)
	: satelliteList(satelliteList)
{}

void Laser::notify() {
	if (!satelliteList)
		return;

	Iterator* it = satelliteList->createIterator();
	while (!it->isDone()) {
		it->currentItem()->communicateSatellite();
	}
}