/**
 * @file CountryMemento.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_COUNTRYMEMENTO_H
#define CONCRETEABSTRACTS_COUNTRYMEMENTO_H

#include <Country.h>

class Country;

class CountryMemento
{
public:
    /**
     * @brief Destroy the Country Memento object
     * 
     */
    ~CountryMemento();

protected:

private:
    Country* state;

    /**
     * @brief Construct a new Country Memento object
     *
     * @param state
     */
    explicit CountryMemento(Country* state);
    friend class Country;
};

#endif //CONCRETEABSTRACTS_COUNTRYMEMENTO_H
