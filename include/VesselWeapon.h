/**
 * @file VesselWeapon.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef VESSELWEAPONS_H
#define VESSELWEAPONS_H

#include <string>
#include <iostream>

class VesselWeapon {

private:
	std::string name;
	int damage;
	int defense;

public:
	/**
	 * @brief Get the Name object
	 * 
	 * @return std::string 
	 */
	virtual std::string getName() = 0;

	/**
	 * @brief Get the Damage object
	 * 
	 * @return int 
	 */
	virtual int getDamage() = 0;

	/**
	 * @brief Get the Defense object
	 * 
	 * @return int 
	 */
	virtual int getDefense() = 0;
};

#endif
