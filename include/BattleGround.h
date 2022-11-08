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
#include <RecruiterContext.h>

class BattleGround: public WarTheatre
{
public:
    /**
     * @brief Construct a new Battle Ground object
     * 
     * @param location 
     */
    explicit BattleGround(std::string location);

    /**
     * @brief Destroy the Battle Ground object
     * 
     */
    ~BattleGround() override;

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
     * @return int 
     */
    WarTheatre* getTrap() override;
    /**
     * @brief The casualties gained from environmental extremities (function could evolve to have other factors)
     * 
     * @param recruitNumber 
     * @return int 
     */
    int penalty(Recruits* recruits) override = 0; //added

    
    RecruiterContext* getDefenders();
    void setDefenders(Recruits* defenders);
    RecruiterContext* getAttackers();
    void setAttackers(Recruits* attackers);
    

protected:

private:
    RecruiterContext* defenders;
    RecruiterContext* attackers;
    
};


#endif