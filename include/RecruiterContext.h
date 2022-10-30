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
#ifndef __RECRUITERCONTEXT_H__
#define __RECRUITERCONTEXT_H__

#include <Recruits.h>
class RecruiterContext
{
private:
    Recruits *state;
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
    // ~RecruiterContext();
};




#endif // __RECUITERCONTEXT_H__