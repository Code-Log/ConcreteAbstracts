/**
 * @file TankCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TANKCREATOR_H
#define TANKCREATOR_H

#include <VesselWeaponCreator.h>
#include <Tanks.h>

class TankCreator : public VesselWeaponCreator {
public:
	/**
	 * @brief Construct a new Tank Creator object
	 * 
	 */
	TankCreator();

	/**
	 * @brief 
	 * 
	 * @return VesselWeapon* 
	 */
	VesselWeapon* produceVesselWeapon() override;

	~TankCreator() override = default;

protected:

private:
};

#endif
