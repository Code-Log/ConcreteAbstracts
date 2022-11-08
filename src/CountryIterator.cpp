#include <CountryIterator.h>

bool CountryIterator::hasNext()
{
    if(currentPos < 7)
    {
        return true;
    }
    return false;
}

void CountryIterator::next()
{
    currentPos++;
}

Country* CountryIterator::current()
{
    return countryList[currentPos];
}

CountryIterator::CountryIterator(Country** countryList)
{
     for(int i = 0; i < 8; i++)
     {
         this->countryList[i] = countryList[i]; 
     }
}
