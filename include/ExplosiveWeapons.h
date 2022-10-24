/**
 * @file ExplosiveWeapons.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef EXPLOSIVEWEAPONS_H
#define EXPLOSIVEWEAPONS_H

#include <AttackWeapon.h>

class ExplosiveWeapons : public AttackWeapon {
public:
	/**
	 * @brief Get the Damage object
	 * 
	 * @return int 
	 */
	int getDamage();

	/**
	 * @brief Get the Name object
	 * 
	 * @return std::string 
	 */
	std::string getName();
};

#endif
