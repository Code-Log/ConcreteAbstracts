/**
 * @file RecruitIterator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_RECRUITITERATOR_H
#define CONCRETEABSTRACTS_RECRUITITERATOR_H

#include <Iterator.h>

class RecruitIterator : public Iterator
{
public:
    /**
     * @brief 
     * 
     */
    void next() override;

    /**
     * @brief Construct a new Recruit Iterator object
     * 
     */
    RecruitIterator();

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool hasNext() override;
private:
};

#endif //CONCRETEABSTRACTS_RECRUITITERATOR_H
