/**
 * @file Soldier.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_SOLDIER_H
#define CONCRETEABSTRACTS_SOLDIER_H

#include <Recruits.h>
class Soldier : public Recruits
{
public:
    /**
     * @brief Construct a new Soldier object
     * 
     */
    Soldier();
    ~Soldier() = default;

protected:

private:
};


#endif // CONCRETEABSTRACTS_SOLDIER_H