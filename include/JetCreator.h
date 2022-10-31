/**
 * @file JetCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef JETCREATOR_H
#define JETCREATOR_H

#include <VesselWeaponCreator.h>
#include <Jets.h>

class JetCreator : public VesselWeaponCreator {


public:
	/**
	 * @brief Construct a new Jet Creator object
	 * 
	 */
	JetCreator();

	/**
	 * @brief 
	 * 
	 * @return VesselWeapon* 
	 */
	VesselWeapon* produceVesselWeapon() override; // VESSEL WEAPON ASK AMBER ?

	~JetCreator() override = default;
};

#endif
