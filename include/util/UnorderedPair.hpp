#ifndef CONCRETEABSTRACTS_UNORDEREDPAIR_HPP
#define CONCRETEABSTRACTS_UNORDEREDPAIR_HPP

/**
 * This is a helper class for creating pairs where
 * (a, b) == (b, a). These are called Unordered pairs,
 * as opposed to ordered pairs, where (a, b) != (b, a)
 */
template<typename T>
struct UnorderedPair
{
    T first;
    T second;

    UnorderedPair(T first, T second) : first(first), second(second) {}

    bool has(T elem) const
    {
        return first == elem || second == elem;
    }

    /**
     * Overloaded equality operator which ensures pair equality is evaluated correctly
     * @return True, if pairs are equal. False, otherwise
     */
    bool operator==(const UnorderedPair& other) const
    {
        return (first == other.first && second == other.second) || (first == other.second && second == other.first);
    }
};

#endif //CONCRETEABSTRACTS_UNORDEREDPAIR_HPP
