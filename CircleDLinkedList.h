//CircleDLinkedList.h
/*#### CircleDLinkedList.h (Header File)
- Member Variables (Private):
  - DNode* cursor;           // Pointer to the current song
  - int n;                   // Current number of songs

- Member Functions (Public):
  - CircleDLinkedList();     // Constructor
  - ~CircleDLinkedList();    // Destructor 
  - bool empty() const;      // Checks if the list is empty
  - int size() const;        // Returns current number of nodes
  - void add(const Song&);   // Adds a song after the current song, and updates cursor to point to the new song
  - void remove();           // Removes the current song, and updates cursor to point to next song
  - void advance();          // Moves to the next song
  - void retreat();          // Moves to the previous song
  - Song getCurrentSong() const;  // Returns the current song
  
    // Prints all songs in list starting from current position (forward or reverse)
  - void print(bool forward = true) const;*/
  
#ifndef CIRCLEDLINKEDLIST_H
#define CIRCLEDLINKEDLIST_H

#include <iostream>
#include "DNode.h"

class CircleDLinkedList {
    private:
        DNode* cursor;  // Pointer to the current song
        int n;  // Current number of songs
    public: 
        CircleDLinkedList();     // Constructor
        ~CircleDLinkedList();    // Destructor 
        bool empty() const;      // Checks if the list is empty
        int size() const;        // Returns current number of nodes
        void add(const Song&);   // Adds a song after the current song, and updates cursor to point to the new song
        void remove();           // Removes the current song, and updates cursor to point to next song
        void advance();          // Moves to the next song
        void retreat();          // Moves to the previous song
        Song getCurrentSong() const;  // Returns the current song
        
        void print(bool forward = true) const; // Prints all songs in list starting from current position (forward or reverse)
    
};

#endif