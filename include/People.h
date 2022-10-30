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
#ifndef CONCRETEABSTRACTS_PEOPLE_H
#define CONCRETEABSTRACTS_PEOPLE_H


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



#endif // CONCRETEABSTRACTS_PEOPLE_H