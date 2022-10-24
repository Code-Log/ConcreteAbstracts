/**
 * @file CountryHistory.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_COUNTRYHISTORY_H
#define CONCRETEABSTRACTS_COUNTRYHISTORY_H

#pragma once

#include <vector>
#include <CountryMemento.h>

class CountryHistory
{
private:
    std::vector<CountryMemento*> history;

public:
    /**
     * @brief Construct a new Country History object
     * 
     */
    CountryHistory() = default;

    /**
     * @brief 
     * 
     * @param memento 
     */
    void addCommit(CountryMemento* memento);

    /**
     * @brief 
     * 
     * @return CountryMemento* 
     */
    CountryMemento* removeCommit();
};

#endif //CONCRETEABSTRACTS_COUNTRYHISTORY_H
