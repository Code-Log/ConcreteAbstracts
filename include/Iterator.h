/**
 * @file Iterator.h
 * @author ConcreteAbstracts 
 * @brief 
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONCRETEABSTRACTS_ITERATOR_H
#define CONCRETEABSTRACTS_ITERATOR_H

class Iterator
{
public:
    /**
     * @brief 
     * 
     */
    virtual void next() = 0;

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool hasNext() = 0;

protected:

private:
};

#endif //CONCRETEABSTRACTS_ITERATOR_H
