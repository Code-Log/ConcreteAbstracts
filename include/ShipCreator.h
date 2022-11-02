/**
 * @file ShipCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SHIPCREATOR_H
#define SHIPCREATOR_H

#include <VesselWeaponCreator.h>
#include <Ships.h>


class ShipCreator : public VesselWeaponCreator {
public:
	/**
	 * @brief Construct a new Ship Creator object
	 * 
	 */
	ShipCreator();

	/**
	 * @brief 
	 * 
	 * @return VesselWeapon* 
	 */
	VesselWeapon* produceVesselWeapon() override;

	~ShipCreator() override = default;

protected:

private:
};

#endif
