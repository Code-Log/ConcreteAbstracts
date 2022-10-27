/**
 * @file RangedWeaponCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef RANGEDWEAPONCREATOR_H
#define RANGEDWEAPONCREATOR_H

#include <AttackWeaponCreator.h>
#include <RangedWeapons.h>

class RangedWeaponCreator : public AttackWeaponCreator {


public:
	/**
	 * @brief Construct a new Ranged Weapon Creator object
	 * 
	 */
	RangedWeaponCreator();

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
