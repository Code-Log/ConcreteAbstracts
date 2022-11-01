/**
 * @file Trap.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TRAP_H
#define TRAP_H

#include "WarTheatre.h"

class Trap : public WarTheatre
{
private:
    WarTheatre* trap;
    bool active;
    int lifespan;

public:
    /**
     * @brief Construct a new Trap object
     * 
     */
    Trap();

    /**
     * @brief Destroy the Trap object
     * 
     */
    ~Trap() override;

    /**
     * @brief 
     * 
     * @param trap 
     */
    void add(WarTheatre* trap) override;

    /**
     * @brief Get the active object
     * 
     * @return true 
     * @return false 
     */
    bool getActive() const;

    /**
     * @brief Set the active object
     * 
     * @param activation 
     */
    void setActive(bool active);

    /**
     * @brief Returns the combined damage of the traps added to the wartheatre
     * 
     * @return int 
     */
    int damageTotal() override;

    /**
     * @brief 
     * 
     * @param decrease 
     */
    void alterLifespan(int decrease);

    WarTheatre* getTrap();

    /**
     * @brief 
     * 
     * @param recruits 
     * @return int 
     */
    int penalty(Recruits* recruits) override;
};



#endif