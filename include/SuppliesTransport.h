#ifndef CONCRETEABSTRACTS_SUPPLIESTRANSPORT_H
#define CONCRETEABSTRACTS_SUPPLIESTRANSPORT_H

#include <Transport.h>

class SuppliesTransport : public Transport
{
public:
    SuppliesTransport() = default;
    void purchase(Recruits* recruits) override;
};

#endif //CONCRETEABSTRACTS_SUPPLIESTRANSPORT_H
