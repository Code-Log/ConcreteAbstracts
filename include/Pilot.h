/**
 * @file Pilot.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_PILOT_H
#define CONCRETEABSTRACTS_PILOT_H

#include <Recruits.h>
class Pilot : public Recruits
{

public:
    /**
     * @brief Construct a new Pilot object
     * 
     */
    Pilot();
    ~Pilot() = default;

protected:

private:
};

#endif // CONCRETEABSTRACTS_PILOT_H