#ifndef STARLINKSATELLITE_H
#define STARLINKSATELLITE_H

#include <string>
#include <cstdio>
#include "Iterator.h"
#include "../Spacecraft/Payload.h"

class Iterator;

using namespace std;

/**
 * @brief The StarlinkSatellite class.
 * This class is used for the StarlinkSatellites that will become part of the payload for
 * a rocket. These satellites can communicate with each other through the use of the Laser
 * class and they can communicate with Earth.
 * This class functions as the Colleague participant
 * @author Ctrl Alt Defeat
 */
class StarlinkSatellite : public Payload
{
public:
	/**
	 * @brief Construct a new StarlinkSatellite object with a default name.
	 *
	 */
	StarlinkSatellite();
	/**
	 * @brief Construct a new StarlinkSatellite object with the provided name.
	 *
	 * @param name The name for the StarlinkSatellite object.
	 */
	StarlinkSatellite(string);
	/**
	 * @brief Destroy the StarlinkSatellite object.
	 *
	 */
	~StarlinkSatellite();
	/**
	 * @brief Communicate with the other satellites.
	 *
	 */
	void CommunicateSatellite();
	/**
	 * @brief COmmunicate with the people on earth.
	 *
	 */
	void CommunicateGround();
	/**
	 * @brief Create a new iterator object to iterate over the StarlinkSatellite objects.
	 *
	 * @return Iterator*
	 */
	Iterator* CreateIterator();
	/**
	 * @brief Clones a StarlinkSatellite object.
	 *
	 * @return Payload*
	 */
	Payload* Clone();
	string GetCargo();
	string GetPassengers();
};

#endif
