/**
 * @file People.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __PEOPLE_H__
#define __PEOPLE_H__


class People
{
private:
    int groupSize;
public:
    /**
     * @brief To get the current size of a given population
     *
     * @return int
     */
    int getGroupSize() const;

    /**
     * @brief to update
     *
     * @param groupSize
     */
    void setGroupSize(int groupSize);

    /**
     * @brief Construct a new People object
     * 
     */
    People();

    /**
     * @brief Destroy the People object
     * 
     */
    virtual ~People();
};



#endif // __PEOPLE_H__