#ifndef CONCRETEABSTRACTS_ATTACKVESSEL_H
#define CONCRETEABSTRACTS_ATTACKVESSEL_H

#include <Transport.h>

class AttackVessel : public Transport
{
public:
    AttackVessel() = default;
    void purchase(Recruits* recruits) override;
};

#endif //CONCRETEABSTRACTS_ATTACKVESSEL_H
