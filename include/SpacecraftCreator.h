/**
 * @file SpacecraftCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SPACECRAFTCREATOR_H
#define SPACECRAFTCREATOR_H

#include <VesselWeaponCreator.h>

class SpacecraftCreator : public VesselWeaponCreator {


public:
	/**
	 * @brief Construct a new Spacecraft Creator object
	 * 
	 */
	SpacecraftCreator();

	/**
	 * @brief 
	 * 
	 * @return VesselWeapon* 
	 */
	VesselWeapon* produceVesselWeapon();

	/**
	 * @brief Get the Total object
	 * 
	 * @return int 
	 */
	int getTotal();
};

#endif
