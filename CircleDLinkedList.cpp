//CircleDLinkedList.cpp

#include <iostream>
#include "CircleDLinkedList.h"

CircleDLinkedList::CircleDLinkedList() // Constructor
: cursor(NULL) , n(0) {}

CircleDLinkedList::~CircleDLinkedList(){// Destructor 
    while (!empty()) remove();
} 

bool CircleDLinkedList::empty() const{// Checks if the list is empty
    return cursor == NULL; //returns as true if the cursor is nullptr
}  

int CircleDLinkedList::size() const{// Returns current number of nodes or songs
    return n; //static int n = number of songs or nodes in the DCLL
}

void CircleDLinkedList::add(const Song& s){//Adds a song after the current song, and updates cursor to point to the new song
    DNode* newSong = new DNode(s); // create new node with s parameter in heap 
    
    if (empty()){ //first song added to an empty list
        newSong->next = newSong; //since this is the first song both pointers
        newSong->prev= newSong; //have to point to itself to ensure circularity
        cursor = newSong; //move cursor to newsong, mneaning the newsong is the current song
    }
    else { //if the playlist already has a song 
        DNode* after = cursor->next; //temporarily store the point that's currently after cursor, needed to insert new node between cursor and after.
        newSong->next = after; //after node’s next pointer points to the node that was after cursor.
        newSong->prev = cursor; //after node’s prev pointer points back to cursor.
        cursor->next = newSong; //cursor->next now points forward to newSong.
        after->prev = newSong; //after->prev now points to newSong
        cursor = newSong; // move cursor to new song
    }
    
	n++;//increment static int n +1 to account for added song
	
}  

void CircleDLinkedList::remove(){ // Removes the current song, and updates cursor to point to next song
    if (empty()) return; //if list is empty we cannot delete anything, if not proceed
    
    DNode* old = cursor; //make a temporary ptr var old and make it point to current node (going to delete)
    
    if (cursor->next == cursor){//checks if next points to itself meaning it only has one node if so
        cursor = nullptr; //only song equals nullptr
    }
    else {//if not the only song do the following
        DNode* before = cursor->prev; //create before node and point it to what comes before the cursor
        DNode* after = cursor->next; //create after node and point it to what comes after the cursor
        before->next = after; //make it so the before node points next to the after node 
        after->prev = before; //make it so the after node points previous to the before node
        cursor = after; //move cursor forward to the next song
    }
    
	delete old; // delete the old node which pointed to the song we want to remove
	n--; //decrement the static int to account for removal of song 

}
void CircleDLinkedList::advance(){// Moves to the next song
    if (!empty()) {//if the list is not empty 
        cursor = cursor->next; //make the cursor point to the next node.
        } 
}

void CircleDLinkedList::retreat(){  // Moves to the previous song
    if (!empty()) {//if the list is not empty
        cursor = cursor->prev; //make the cursor point to the previous node.
    }
}

Song CircleDLinkedList::getCurrentSong() const{// Returns the current song
    if (empty()) {
        throw std::runtime_error("The playlist is empty."); //throw or call an exception, that says list is empty
    }
    return cursor->elem;//Return the song object 
}

void CircleDLinkedList::print(bool forward) const{//Prints all songs in list starting from current position (forward or reverse)
    if (empty()) {
        std::cout << "Playlist is empty." << std::endl;
        return; 
    }
    
    DNode* temp = cursor; //create a temporary node and sets it to current song or cursor without using actual cursor 
    for (int i = 0; i < n; i++){
        std::cout << "Song " << (i + 1) << ": " << temp->elem.getSongTitle() << " by " << temp->elem.getSingerName() << std::endl;
        //prints out 'song' followed by the 'song number in the playlist', song title, ' by ', and then singer name
        if (forward){
            temp = temp->next; 
            }
        else {
            temp = temp->prev;
            }
        }
        
        std::cout << std::endl;
}  
    
