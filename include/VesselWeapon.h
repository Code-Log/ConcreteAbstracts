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
     * @brief Destroy the VesselWeapon object
     * 
     */
	virtual ~VesselWeapon() = default;

protected:
    std::string name;
    int damage = 500;
    int defense = 100;
    int durability = 50;

private:
};

#endif
