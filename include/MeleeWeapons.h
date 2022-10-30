/**
 * @file MeleeWeapons.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MELEEWEAPONS_H
#define MELEEWEAPONS_H

#include <AttackWeapon.h>

class MeleeWeapons : public AttackWeapon {


public:
	/**
	 * @brief Get the Damage object
	 * 
	 * @return int 
	 */
	int getDamage() override;

	/**
	 * @brief Get the Name object
	 * 
	 * @return std::string 
	 */
	std::string getName() override;

	/**
	 * @brief Get the Durability object
	 * 
	 * @return int 
	 */
	int getDurability() override;

	/**
	 * @brief Set the Durability object
	 * 
	 * @return void 
	 */
	void setDurability(int durability) override;

    /**
     * @brief Destroy the MeleeWeapons object
     * 
     */
	~MeleeWeapons() override = default;
};

#endif
