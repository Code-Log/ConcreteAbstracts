/**
 * @file AttackWeaponCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ATTACKWEAPONCREATOR_H
#define ATTACKWEAPONCREATOR_H
#include <AttackWeapon.h>

class AttackWeaponCreator {
public:
	/**
	 * @brief Construct a new Attack Weapon Creator object
	 * 
	 */
	AttackWeaponCreator();

	/**
	 * @brief 
	 * 
	 * @return AttackWeapon* 
	 */
	AttackWeapon* produce();

protected:
	/**
	 * @brief 
	 * 
	 * @return AttackWeapon* 
	 */
	virtual AttackWeapon* produceAttackWeapon() = 0;

public:
	virtual ~AttackWeaponCreator() = default;
};

#endif
