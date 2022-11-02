/**
 * @file ExplosiveWeaponCreator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef EXPLOSIVEWEAPONCREATOR_H
#define EXPLOSIVEWEAPONCREATOR_H

#include <AttackWeaponCreator.h>
#include <ExplosiveWeapons.h>

class ExplosiveWeaponCreator : public AttackWeaponCreator {
public:
	/**
	 * @brief Construct a new Explosive Weapon Creator object
	 * 
	 */
	ExplosiveWeaponCreator();

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
