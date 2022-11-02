/**
 * @file NuclearWeaponCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef NUCLEARWEAPONCREATOR_H
#define NUCLEARWEAPONCREATOR_H

#include <AttackWeaponCreator.h>
#include <NuclearWeapons.h>

class NuclearWeaponCreator : public AttackWeaponCreator {
public:
	/**
	 * @brief Construct a new Nuclear Weapon Creator object
	 * 
	 */
	NuclearWeaponCreator();

	/**
	 * @brief 
	 * 
	 * @return AttackWeapon* 
	 */
	AttackWeapon* produceAttackWeapon() override;

protected:

private:
};

#endif
