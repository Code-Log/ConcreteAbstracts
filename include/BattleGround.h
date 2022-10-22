/*{Decorator Design Pattern: abstractComponent ???}*/
#ifndef BATTLEGROUNDS_H
#define BATTLEGROUNDS_H

#include <WarTheatre.h>

class BattleGround: public WarTheatre
{
public:
    BattleGround(std::string location);
    ~BattleGround();

    void add(WarTheatre* trap) override;
    int damageTotal() override;

    virtual int penalty(int* recruitNumber) = 0; //added
};


#endif