/**
 * @file BattleGround.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BATTLEGROUNDS_H
#define BATTLEGROUNDS_H

#include <WarTheatre.h>

class BattleGround: public WarTheatre
{
public:
    /**
     * @brief Construct a new Battle Ground object
     * 
     * @param location 
     */
    BattleGround(std::string location);

    /**
     * @brief Destroy the Battle Ground object
     * 
     */
    ~BattleGround();

    /**
     * @brief 
     * 
     * @param trap 
     */
    void add(WarTheatre* trap) override;

    /**
     * @brief 
     * 
     * @return int 
     */
    int damageTotal() override;

    /**
     * @brief 
     * 
     * @param recruitNumber 
     * @return int 
     */
    virtual int penalty(int* recruitNumber) = 0; //added
};


#endif