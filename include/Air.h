/**
 * @file Air.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef AIR_H
#define AIR_H

#include <BattleGround.h>

class Air : public BattleGround
{
private:
    
public:
    /**
     * @brief Construct a new Air object
     * 
     */
    Air();

    /**
     * @brief Destroy the Air object
     * 
     */
    ~Air() override;

    /**
     * @brief The casualties gained from environmental extremities (function could evolve to have other factors)
     * 
     * @param recruits
     * @return int 
     */
    int penalty(Recruits* recruits) override;
    
    /**
     * @brief 
     * 
     * @return int 
     */
    int gForce();
};


#endif