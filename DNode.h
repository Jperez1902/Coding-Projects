//DNode.h

/*#### DNode.h (Header File)
- Member Variables (Private):
  - Song elem;               // Song object stored in the node
  - DNode* next;             // Pointer to the next node
  - DNode* prev;             // Pointer to the previous node

- Member Variables (Public):
  - static int activeNodes;  // Static variable to track the number of active 
                              // nodes

- Member Functions (Private):
    // Constructor increments activeNodes
  - DNode(const Song&, DNode* p = nullptr, DNode* n = nullptr); 
    

- Member Functions (Public):
  - ~DNode();  */
  
#ifndef DNODE_H
#define DNODE_H

#include <iostream>
#include "Song.h"
  

class DNode{
    private: 
        Song elem;  // Song object stored in the node
        DNode* next;  // Pointer to the next node
        DNode* prev;  // Pointer to the previous node
        DNode(const Song&, DNode* p = nullptr, DNode* n = nullptr); // Constructor increments activeNodes
        friend class CircleDLinkedList;
    public:
        static int activeNodes;  // Static variable to track the number of active nodes 
        ~DNode();
                              
}; 

#endif