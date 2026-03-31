//NodeDictionaryG.h

#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include "DNodeG.h"
#include "Range.h"
#include "IteratorG.h"
#include <iostream>

template <typename K, typename V>
class NodeDictionaryG{
    private:
        int uKeys;  // Current number of unique keys in the dictionary.
        int n;  // Total number of entries in the dictionary.
        DNodeG<K,V>* header;  // Sentinel node at the start of the list.
        DNodeG<K,V>* trailer;  // Sentinel node at the end of the list.
        
    public:
        NodeDictionaryG()  // Constructor to initialize the dictionary with header and trailer nodes.
        : uKeys(0) , n(0)  {
            header = new DNodeG<K,V>();
            trailer = new DNodeG<K,V>();
            header->next = trailer;
            trailer->prev = header;
        }
        
        ~NodeDictionaryG(){// Destructor 
            while (!empty()){ 
                erase(begin());
            }
            delete header;
            delete trailer;
        }
        
        int size() const{ // Returns the total number of entries.
            return n;
        }
        
        int uniqueKeys() const{ // Returns the number of unique keys.
            return uKeys;
        }
        
        bool empty() const{ // Checks if the dictionary is empty.
            return n == 0;
        }
        
        IteratorG<K,V> begin() const{ // Returns an iterator pointing to the first entry.
            return IteratorG<K,V>(header->next);
        }
        
        IteratorG<K,V> end() const{ //Returns an iterator pointing past the last entry.
            return IteratorG<K,V>(trailer);
        }
        
        IteratorG<K,V> find(const K& k) const{ // Finds the first entry with the given key.
            IteratorG<K,V> p = begin();
            
            while(p!=end()){
                if(k == p.getK()){
                    return p; 
                }
                ++p;
            }
            return end();
        }
        
        Range<K,V> findAll(const K& k){// Returns a range of entries with the given key.
    	    IteratorG<K,V> b = find(k);
    	    
            if (b == end()){
                return Range<K,V>(end(), end());
            }
            
            IteratorG<K,V> e = b;
            while (e != end() && e.getK() == k){
                ++e;
            }
            return Range<K,V> (b,e);
        }
        
        // Inserts a key-value pair.
        //If there are entry with key == k the new entry will be inserted after the last entry with key = k.
        IteratorG<K,V> put(const K& k, const V& v){
            IteratorG<K,V> p = find(k);
            
            if (p == end()){
                uKeys++;
                DNodeG<K,V>* node = new DNodeG<K,V>(Entry<K,V>(k, v),trailer->prev,trailer);
                
                trailer->prev->next = node;
                trailer->prev = node;

                n++;
                return IteratorG<K,V>(node);
            }
            
            IteratorG<K,V> q = p;
            while (q != end() && q.getK() == k){//the key already exist
                ++q;//keep going through all of the nodes with the same key or until we hit end()
            }
            
            DNodeG<K,V>* before = q.u->prev;
            DNodeG<K,V>* after  = q.u;
            
            DNodeG<K,V>* node = new DNodeG<K,V>(Entry<K,V>(k, v),before,after);

            before->next = node;
            after->prev = node;
            
            n++;
            return IteratorG<K,V>(node);
        }
        
	    void erase(const K& k){// Removes the first entry with the given key.
	        IteratorG<K,V> p = find(k);

            if(p != end()){
                erase(p);
            }
        }
	    
	    void erase(const IteratorG<K,V>& p){// Removes the entry at the given iterator.
            if (p == end()){
                return;
            }
            
            K key = p.getK();//for future reference to update uKey
            
            DNodeG<K,V> * old = p.u;
            DNodeG<K,V> * before = p.u->prev;
            DNodeG<K,V> * after = p.u->next;
                    
            before->next = after;
            after->prev = before;
            delete old;
            n--;
            
            if (find(key) == end()) {//checks if the key is still in the list
                uKeys--; //decrements the unique keys variable
            }
            return;
        }
	    
	    void erase(const Range<K,V>& r){// Removes all entries in the specified range.
	        IteratorG<K,V> b = r.getB();
            IteratorG<K,V> e = r.getE();

            while (b != e) {
                K key = b.getK();             // Remember the key before erasing
                IteratorG<K,V> nextiterator = b;
                ++nextiterator;              // Move iterator forward before deleting
                erase(b);                    // Use the existing erase(iterator) function
                b = nextiterator;           // Continue with next node
	        } 
	    }
    	
	    void print(){
	        IteratorG<K,V> p = begin();
	        
	        while (p != end()){ 
	            std::cout << p.getK() << " : " << p.getV() << std::endl;
	            ++p;
	        }
	    }
	    
	    void print(const Range<K,V>& r, bool forward = true) const{// Prints all entries in the specified range.
            if (forward) {
                IteratorG<K,V> p = r.getB();
                IteratorG<K,V> e  = r.getE();
            
                while (p != e){
                    std::cout << p.getK() << " : " << p.getV() << std::endl;
                    ++p;
                }
            }
            else {
                IteratorG<K,V> p = r.getB();
                IteratorG<K,V> e  = r.getE();
                
                while (e != p){
                    --e;
                    std::cout << e.getK() << " : " << e.getV() << std::endl;
                    
                }
                    
            }
            
	    } 

};

#endif






