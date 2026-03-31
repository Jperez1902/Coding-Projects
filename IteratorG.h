//IteratorG.h
    
#ifndef ITERATORG_H
#define ITERATORG_H

#include "DNodeG.h"

template <typename K, typename V>
class IteratorG{
    private:
        DNodeG<K,V>* u;  // Pointer to the current node in the list.
        
        template <typename, typename>
        friend class NodeDictionaryG;
        
    public:
        IteratorG(DNodeG<K,V>* v = nullptr) : u(v) {}
        
        const Entry<K,V>& entry() const{//returns a read-only reference to the current key–value pair
            return u->elem;
        }

        const K& getK() const { //getter for the key, makes it usable without exposing the node or entry structure 
            return u->elem.getK();
        }

        const V& getV() const {//getter for the value, makes it usable without exposing the node or entry structure 
            return u->elem.getV();
        }
    
        const V& operator*(){// Returns a reference to the value of the current node.
            return u->elem.getV();
        } 
        
        bool operator==(const IteratorG& p) const{// Compares the current iterator with another for equality.
            return u == p.u;
        }
        
        bool operator!=(const IteratorG& p) const{// Compares the current iterator with another for inequality.
            return u != p.u;
        }
        
        IteratorG& operator++(){// Moves the iterator to the next position in the list.
            u = u->next;
            return *this;
        }
        
        IteratorG& operator--(){// Moves the iterator to the previous position in the list.
            u = u->prev;
            return *this;
        }
        
};

#endif