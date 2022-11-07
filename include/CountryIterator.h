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
#ifndef CONCRETEABSTRACTS_COUNTRYITERATOR_H
#define CONCRETEABSTRACTS_COUNTRYITERATOR_H

#include <Iterator.h>

class CountryIterator : public Iterator
{
public:
    /**
     * @brief 
     * 
     */
    void next() override;

    /**
     * @brief Construct a new Country Iterator object
     * 
     */
    CountryIterator(Country** countryList);

    /**
     * @brief 
     * 
     */
    Country* current() override;

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool hasNext() override;

protected:
    int currentPos = 0;
    Country* countryList[8];
private:
};

#endif //CONCRETEABSTRACTS_RECRUITITERATOR_H
