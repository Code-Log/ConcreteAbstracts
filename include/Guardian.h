/**
 * @file Guardian.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_GUARDIAN_H
#define CONCRETEABSTRACTS_GUARDIAN_H


#include <Recruits.h>
class Guardian : public Recruits
{
public:
    /**
     * @brief Construct a new Guardian object
     * 
     */
    Guardian();
    ~Guardian() = default;
    
protected:

private:
};

#endif // CONCRETEABSTRACTS_GUARDIAN_H
