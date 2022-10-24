/**
 * @file BattleRegistry.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_BATTLEREGISTRY_H
#define CONCRETEABSTRACTS_BATTLEREGISTRY_H

#pragma once

#include <Registry.h>
#include <vector>

class BattleRegistry : public Registry
{
private:
    std::vector<UnorderedPair<Country*>> battles;

public:
    /**
     * @brief Construct a new Battle Registry object
     * 
     */
    BattleRegistry();

    /**
     * @brief Destroy the Battle Registry object
     * 
     */
    ~BattleRegistry() override = default;

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

#endif //CONCRETEABSTRACTS_BATTLEREGISTRY_H
