#ifndef AIR_H
#define AIR_H

#include "BattleGround.h"

class Air : public BattleGround
{
    private:
        /* data */
    public:
        Air(/* args */);
        ~Air();

        virtual int penalty(int* recruitNumber);
        int gForce();
};


#endif