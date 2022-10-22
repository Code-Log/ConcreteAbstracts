#include <iostream>

#include <Country.h>
//#include "WarTheatre.h"
#include <string>

using namespace std;

int main() {
    Country* x = new Country("jack");

    Country* y = x->cloneCountry();

    cout << x->getName() << endl;   
    delete y;
    cout << "hello world" << endl;

    return 0;
}