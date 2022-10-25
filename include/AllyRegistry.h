/**
 * @file AllyRegistry.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_ALLYREGISTRY_H
#define CONCRETEABSTRACTS_ALLYREGISTRY_H

#pragma once

#include <Registry.h>
#include <util/UnorderedPair.hpp>

class AllyRegistry : public Registry
{
private:
    std::vector<UnorderedPair<Country*>> allies;

public:
    /**
     * @brief Construct a new Ally Registry object
     * 
     */
    AllyRegistry();

    /**
     * @brief Destroy the Ally Registry object
     * 
     */
    ~AllyRegistry() override = default;

    /**
     * @brief 
     * 
     * @param country1 
     * @param country2 
     */
    void addRecord(Country* country1, Country* country2) override;

    /**
     * @brief Get the Records object
     * 
     * @param country 
     * @return std::vector<UnorderedPair<Country*>> 
     */
    std::vector<UnorderedPair<Country*>> getRecords(Country* country) override;
};

#endif //CONCRETEABSTRACTS_ALLYREGISTRY_H
