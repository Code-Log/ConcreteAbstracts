/**
 * @file Registry.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_REGISTRY_H
#define CONCRETEABSTRACTS_REGISTRY_H

#pragma once

#include <vector>
#include <Country.h>
#include <util/UnorderedPair.hpp>

class Registry
{
public:
    /**
     * @brief 
     * 
     * @param country1 
     * @param country2 
     */
    virtual void addRecord(Country* country1, Country* country2) = 0;

    /**
     * @brief Get the Records object
     * 
     * @param country 
     * @return std::vector<UnorderedPair<Country*>> 
     */
    virtual std::vector<UnorderedPair<Country*>> getRecords(Country* country) = 0;

    /**
     * @brief Destroy the Registry object
     * 
     */
    virtual ~Registry() = default;

protected:
    std::vector<Country*> countries;

private:
};

#endif //CONCRETEABSTRACTS_REGISTRY_H
