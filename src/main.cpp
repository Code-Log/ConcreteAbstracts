#include <iostream>
#include <Country.h>
#include <AbstractCountry.h>
#include "WarTheatre.h"
#include <string>

using namespace std;

int main() {
    AbstractCountry* x = new Country("jack");

    AbstractCountry* y = x->cloneCountry(); 

    cout << x->getName() << endl;   
    delete y;
    cout << "hello world" << endl;

    return 0;
}
