/**
 * @file Spacecraft.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <VesselWeapon.h>
#include <Spacecraft.h>

class Spacecraft : public VesselWeapon {
public:
	/**
	 * @brief Get the Damage object
	 * 
	 * @return int 
	 */
	int getDamage() override;

	/**
	 * @brief Get the Defense object
	 * 
	 * @return int 
	 */
	int getDefense() override;

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
     * @brief Destroy the Spacecraft object
     * 
     */
	~Spacecraft() override = default;

protected:

private:
};

#endif
