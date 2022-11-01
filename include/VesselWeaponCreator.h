/**
 * @file VesselWeaponCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef VESSELWEAPONCREATOR_H
#define VESSELWEAPONCREATOR_H

#include <VesselWeapon.h>

class VesselWeaponCreator {

protected:
	int price;

public:
	/**
	 * @brief Construct a new Vessel Weapon Creator object
	 * 
	 */
	VesselWeaponCreator();

	/**
	 * @brief 
	 * 
	 * @return VesselWeapon* 
	 */
	VesselWeapon* produce();

protected:
	/**
	 * @brief 
	 * 
	 * @return VesselWeapon* 
	 */
	virtual VesselWeapon* produceVesselWeapon() = 0;

public:
	/**
	 * @brief Get the Price object
	 * 
	 * @return int 
	 */
	int getPrice();

	virtual ~VesselWeaponCreator() = default;
};

#endif
