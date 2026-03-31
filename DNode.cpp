//DNode.cpp

#include "DNode.h"

//int DNode::activeNodes = 0; // Define the static variable to keep track how many DNode objects currently exist, initalized at 0
                            //Useful for debugging memory leaks or active node tracking.

DNode::DNode(const Song& s, DNode* p, DNode* n) // Constructor (private, accessible only to CircleDLinkedList)
    : elem(s), next(n), prev(p) { //private data
    ++activeNodes; //Increments the static counter to track the number of active DNode objects.
}

DNode::~DNode() { // Destructor
    --activeNodes;
}