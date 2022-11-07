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
#include<Recruits.h>
#include<vector>
#include<iterator>


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
    RecruitIterator(std::vector<Recruits*> rec);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool hasNext() override;

    /**
     * @brief Get the Iterator object
     * 
     * @return     std::vector<Recruits*>
     */
    std::vector<Recruits*>::iterator getCurrent();

protected:

private:
    std::vector<Recruits*>::iterator head;
    std::vector<Recruits*>::iterator current;
    std::vector<Recruits*>::iterator end;
};

#endif //CONCRETEABSTRACTS_RECRUITITERATOR_H
