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

	virtual ~AttackWeaponCreator() = default;
	/**
	 * @brief Get the Price object
	 * 
	 * @return int 
	 */
	int getPrice() const;
	/**
	 * @brief Set the Price attribute
	 * 
	 * @param price 
	 */
	void setPrice(int price);

protected:
    int price;

    /**
	 * @brief
	 *
	 * @return AttackWeapon*
	 */
    virtual AttackWeapon* produceAttackWeapon() = 0;

};

#endif
