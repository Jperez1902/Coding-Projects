//Entry.h

#ifndef ENTRY_H
#define ENTRY_H

template <typename K, typename V>
class IteratorG;

template <typename K, typename V>
class Entry{
    private:
        K _key;
        V _value;
        
    public:
        Entry(const K& k = K(), const V& v = V()):_key(k), _value(v){ // Constructor to initialize an entry with a key and value.
        }
        
         ~Entry(){// Destructor to release resources.
        } 
        
        const K& getK() const{
            return _key;
        }
        
        const V& getV() const{
            return _value;
        }
        
        void setK(const K& k){
            _key = k;
        }
        
        void setV(const V& v){
            _value = v;
        }
    
};

#endif