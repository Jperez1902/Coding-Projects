//EnglishDictionary.h

#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H

#include "NodeDictionaryG.h"
#include <iostream>
#include <string>
using std::string;


class EnglishDictionary{
    private:
        string name;  // Name of the dictionary.
        NodeDictionaryG<string, string> dictionary;  // Stores the words and their definitions.

    public:
        EnglishDictionary(const string& n) : name(n) {}// Constructor to initialize the dictionary with a name.
        
        ~EnglishDictionary() {} // Destructor to release resources.  
        
        int words() const{ // Returns the total number of words in the dictionary.
            return dictionary.size();
        }
        
        int uniqueWords() const{// Returns the number of unique words.
             return dictionary.uniqueKeys();
        } 
        
        bool empty() const{
            return dictionary.empty();
        }
        
        void add(const string& w, const string& d){// Adds a new word and its definition.
            dictionary.put(w,d);
        } 
        
        
        void add(const Entry<string, string>& e) {
            // Extracts the key (word) and value (definition) from the Entry object (e)
            // and passes them to the underlying NodeDictionaryG's put function.
            dictionary.put(e.getK(), e.getV());
        }
        
        void deleteFirst(const string& d){
            dictionary.erase(d);
        }
        
        void deleteWord(const string& w){// Deletes all definitions of a word.
            // Get the range of all entries with the word w
            Range<string, string> r = dictionary.findAll(w);

            // Use NodeDictionaryG's erase(Range) function to delete all definitions of the word
            dictionary.erase(r);
        }
    
    
        void printDictionary(bool forward, IteratorG<string, string> it = IteratorG<string, string>()){//Should be implemented as an recursive function. Prints all entries in the dictionary (true = forward, false = reverse).
            
            if (it == IteratorG<string, string>()) {
                it = dictionary.begin();
                }
        
            //base case: stop recursion
            if (it == dictionary.end()){
                return;
            }
            
            
            IteratorG<string, string> nextIt = it; 
            ++nextIt; //move the iterator forward to the next recursion
            //goes forward even if you're printing forward or reverse.
            //what changes is that 
            
            if (forward){
            // print current node first, then recurse
                std::cout << it.getK() << " : " << it.getV() << std::endl;
                printDictionary(true, nextIt);
            } else {
            // recurse first (tail call), then print after returning
                printDictionary(false, nextIt);
                std::cout << it.getK() << " : " << it.getV() << std::endl;
            }
            
        }
        
        void printWord(const string& w, bool direction = true){ // Prints all definitions for a given word.
            Range<string, string> r = dictionary.findAll(w);
            dictionary.print(r,direction);
        }
        
        Entry<string, string> find(string w){// Finds the first entry for a given word.
            IteratorG<string, string> p = dictionary.find(w);
            
            if (p != dictionary.end()) {
                return Entry<string, string>(p.getK(), p.getV());
            }
            // Otherwise return a default (empty) entry
            return Entry<string, string>();
        }  

};

#endif