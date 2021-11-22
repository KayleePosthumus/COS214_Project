#ifndef LASER_H
#define LASER_H

#include "../Spacecraft/FalconRocket/Falcon9.h"
#include "StarlinkSatellite.h"

/**
 * @brief The Laser class.
 * This class will iterate over all the satellites registered to the satelliteList
 * and allow them to communicate with each other.
 * This class functions as the Mediator participant.
 * @author Ctrl Alt Defeat
 */
class Laser
{
private:
	Payload* satelliteList;
public:
	/**
	 * @brief Construct a new Laser object.
	 *
	 */
	Laser();
	/**
	 * @brief Destroy the Laser object.
	 *
	 */
	Laser(Payload*);
	/**
	 * @brief Construct a new Laser object.
	 *
	 * @param newSatelliteList The list of StarlinkSatellites.
	 */
	~Laser();
	/**
	 * @brief Notify all the Payload objects in satelliteList.
	 *
	 */
	void notify();
	/**
	 * @brief Adds a Payload object to the satelliteList.
	 *
	 * @param satellite
	 */
	void addSatellite(Payload*);
};

#endif
