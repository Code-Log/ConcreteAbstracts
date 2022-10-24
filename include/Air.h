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
    ~Air();

    /**
     * @brief 
     * 
     * @param recruitNumber 
     * @return int 
     */
    int penalty(int* recruitNumber) override;
    
    /**
     * @brief 
     * 
     * @return int 
     */
    int gForce();
};


#endif