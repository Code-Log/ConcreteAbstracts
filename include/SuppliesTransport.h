/**
 * @file SuppliesTransport.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_SUPPLIESTRANSPORT_H
#define CONCRETEABSTRACTS_SUPPLIESTRANSPORT_H

#include <Transport.h>

class SuppliesTransport : public Transport
{
public:
    /**
     * @brief Construct a new Supplies Transport object
     * 
     */
    SuppliesTransport() = default;

    /**
     * @brief 
     * 
     * @param recruits 
     */
    void purchase(Recruits* recruits) override;

    /**
     * @brief 
     * 
     * @param recruits 
     */
    void purchaseInput(Recruits* recruits) override;

protected:

private:
};

#endif //CONCRETEABSTRACTS_SUPPLIESTRANSPORT_H
