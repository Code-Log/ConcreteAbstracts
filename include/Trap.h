/*{Decorator Design Pattern: Decorator}*/
#ifndef TRAP_H
#define TRAP_H

#include "WarTheatre.h"

class Trap : public WarTheatre
{
private:
    WarTheatre* trap;
    bool Active;
    int lifespan;

public:
    Trap();
    ~Trap();

    void add(WarTheatre* trap) override;

    bool getActive();
    void setActive(bool activation);

    int damageTotal() override;
    void alterLifespan(int decrease);

    int penalty(int* recruitNumber) override;
};



#endif