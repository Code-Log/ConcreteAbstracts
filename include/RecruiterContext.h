/**
 * @file RecruiterContext.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_RECRUITERCONTEXT_H
#define CONCRETEABSTRACTS_RECRUITERCONTEXT_H

#include <Recruits.h>
class RecruiterContext
{
public:
    /**
     * @brief Construct a new Recuiter Context object
     * 
     */
    RecruiterContext();

    /**
     * @brief 
     * 
     */
    void request();

    /**
     * @brief Set the State object
     * 
     * @param state 
     */
    void setState(Recruits *state);

    /**
     * @brief Get the State object
     * 
     * @return Recruits* 
     */
    Recruits* getState(); //for testing purposes

protected:

private:
    Recruits *state;
};




#endif // CONCRETEABSTRACTS_RECRUITERCONTEXT_H