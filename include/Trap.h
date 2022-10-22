/*{Decorator Design Pattern: Decorator}*/
#ifndef TRAP_H
#define TRAP_H

#include "WarTheatre.h"

class Trap : public WarTheatre
{
    private:
        WarTheatre* trap;
        bool Active; //isActive to Active
        int lifespan; //added. when reaches 0 set Active to false. decreases whenever getDamage is called
    
    public:
        Trap(/* args */);
        ~Trap();

        void add(WarTheatre* trap);

        bool getActive();
        void setActive(bool activation);

        int damageTotal();
        void alterLifespan(int decrease); //added

        virtual int penalty(int* recruitNumber); //added
};



#endif