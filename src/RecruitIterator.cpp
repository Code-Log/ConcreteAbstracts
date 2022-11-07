#include <RecruitIterator.h>

bool RecruitIterator::hasNext()
{
   if(current == end)
   {
        return true;
   }
   else
   {
        return false;
   }
}

void RecruitIterator::next()
{
    current++;
}

RecruitIterator::RecruitIterator(std::vector<Recruits*> rec)
{
    head = rec.begin();
    end = rec.end();
    current = rec.begin();
}

std::vector<Recruits*>::iterator RecruitIterator::getCurrent()
{
    return current;
}
