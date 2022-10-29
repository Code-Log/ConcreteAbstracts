/**
 * @file AttackWeapon.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ATTACKWEAPON_H
#define ATTACKWEAPON_H

#include <string>
#include <iostream>

class AttackWeapon {

private:
	std::string name;
	int damage = 100;
	int durability = 100;

public:
	/**
	 * @brief Get the Damage object
	 * 
	 * @return int 
	 */
	virtual int getDamage() = 0;

	/**
	 * @brief Get the Name object
	 * 
	 * @return std::string 
	 */
	virtual std::string getName() = 0;

	/**
	 * @brief Get the Durability object
	 * 
	 * @return int 
	 */
	virtual int getDurability() = 0;

	/**
	 * @brief Set the Durability object
	 * 
	 * @return void 
	 */
	virtual void setDurability(int durability) = 0;

	/**
     * @brief Destroy the AttackWeapon object
     * 
     */
	virtual ~AttackWeapon();
};

#endif
