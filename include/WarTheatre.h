/*{Decorator Design Pattern: Component}*/

#ifndef WARTHEATRES_H
#define WARTHEATRES_H

#include <string>

using namespace std;
//#include "Country.h"

class WarTheatre
{
    private:
        int damage; 
        string location; // just for convenience. Land, sea, space or air

       
    public: 
        WarTheatre(string location);
        ~WarTheatre();

        std::string getLocation(); //added

        virtual void add(WarTheatre* trap)=0;

        int getDamage(); 
        void setDamage(int damage);
        virtual int damageTotal()=0; //function influences trap values so should only be called when used against enemies. If needed we can add a seeDamage() that won't alter traps

        virtual int penalty(int* recruitNumber)=0; //added
};


#endif