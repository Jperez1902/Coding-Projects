//Range.h

#ifndef RANGE_H
#define RANGE_H

#include "IteratorG.h"

template <typename K, typename V>
class Range { // an iterator range
    private:
        IteratorG<K,V> b; // front of range
        IteratorG<K,V> e; // end of range
    public:
        Range(const IteratorG<K,V>& _beg, const IteratorG<K,V>& _end): b(_beg), e(_end) { } // constructor
        const IteratorG<K,V>& getB() const { return b; } // get beginning
        const IteratorG<K,V>& getE() const { return e; } // get end

};

#endif