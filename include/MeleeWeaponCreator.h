/**
 * @file MeleeWeaponCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MELEEWEAPONCREATOR_H
#define MELEEWEAPONCREATOR_H

#include <AttackWeaponCreator.h>
#include <MeleeWeapons.h>

class MeleeWeaponCreator : public AttackWeaponCreator {


public:
	/**
	 * @brief Construct a new Melee Weapon Creator object
	 * 
	 */
	MeleeWeaponCreator();

	/**
	 * @brief 
	 * 
	 * @return AttackWeapon* 
	 */
	AttackWeapon* produceAttackWeapon();

	/**
	 * @brief Get the Total object
	 * 
	 * @return int 
	 */
	int getTotal();
};

#endif
