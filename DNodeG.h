//DNodeG.h

#ifndef DNODEG_H
#define DNODEG_H

#include "Entry.h"

template <typename K, typename V>
class IteratorG;

template <typename K, typename V>
class DNodeG {
    public:
        Entry<K,V> elem;
        DNodeG<K,V>* next;
        DNodeG<K,V>* prev;
        
        static int activeNodes; 
        
        friend class IteratorG<K,V>;
        
    //public: 
        DNodeG(const Entry<K, V>& e = Entry<K,V>(), DNodeG<K, V>* p = nullptr, DNodeG<K, V>* n = nullptr)
        : elem(e), next(n), prev(p) {//Constructor to initialize a node with a key-value pair,
                                    //next, and previous pointers, also increments `activeNodes`.
            ++activeNodes;
        } 

        ~DNodeG(){// Destructor to decrement `activeNodes` when a node is destroyed.
            --activeNodes; 
        }  

};

template <typename K, typename V>
int DNodeG<K,V>::activeNodes = 0; // Define the static variable to keep track how many DNodeG objects currently exist, initalized at 0
                            //Useful for debugging memory leaks or active node tracking.

#endif