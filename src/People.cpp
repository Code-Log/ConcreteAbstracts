// #include "../include/People.h"
#include <People.h>
People::People(/* args */)
{
    
}

People::~People()
{
    
}

int People::getGroupSize() const
{
    return groupSize;
}

Country* People::getCountry()
{
    return country;
}
void People::setCountry(Country* country){
    this->country = country;
}

void People::setGroupSize(int groupSize)
{
    People::groupSize = groupSize;
}
