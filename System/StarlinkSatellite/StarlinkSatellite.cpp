#include "StarlinkSatellite.h"

StarlinkSatellite::StarlinkSatellite()
{}

StarlinkSatellite::StarlinkSatellite(std::string name)
	: name(name)
{}

StarlinkSatellite::~StarlinkSatellite() {}

StarlinkSatellite* StarlinkSatellite::clone(StarlinkSatellite* original) {
	StarlinkSatellite* copy = new StarlinkSatellite(original->name);
	copy->next = original->next;
	return copy;
}

StarlinkSatellite* StarlinkSatellite:: getNext() {
	return next;
}

std::string StarlinkSatellite::getName() {
	return name;
}

void StarlinkSatellite::communicateSatellite() {
	printf("%s Testing communication with satellites\n", name);
}

void StarlinkSatellite::communicateGround() {
	printf("%s Testing communication with ground\n", name);
}