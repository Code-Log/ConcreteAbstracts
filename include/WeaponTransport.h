#ifndef CONCRETEABSTRACTS_WEAPONTRANSPORT_H
#define CONCRETEABSTRACTS_WEAPONTRANSPORT_H

#pragma once

#include <Transport.h>

class WeaponTransport : public Transport
{
public:
    WeaponTransport() = default;
    void purchase(Recruits* recruits) override;
};

#endif //CONCRETEABSTRACTS_WEAPONTRANSPORT_H
