//MusicPlayer.cpp

#include <iostream>
#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(std::string typeplayer){// Constructor 
    type = typeplayer;
}    

MusicPlayer::~MusicPlayer(){//CircleDLinkedList destroys nodes , string type destroys automatically
//when this goes out of scope C++ calls ~CircleDLinkedList and destroys the object created, avoid double destruction
    std::cout << "MusicPlayer of type '" << type << "' destroyed." << std::endl;
}


void MusicPlayer::play(){// Plays the current song (prints the song details)
    if (playlist.empty()){
        std::cout << type << " has no songs in it." << std::endl;
        return;
    }   
    
    Song current = playlist.getCurrentSong();
    std::cout << type << " is now playing " << current.getSongTitle() << " by " << current.getSingerName() << std::endl; 
    
}

void MusicPlayer::next(){// Moves to the next song and plays it
    if (playlist.empty()){
        std::cout << type << " has no songs in it." << std::endl;
        return;
    }   
    
    playlist.advance();
    Song current = playlist.getCurrentSong();
    std::cout << type << " is now playing " << current.getSongTitle() << " by " << current.getSingerName() << std::endl; 
     //calls CircleDLinkedList::advance() and then the CircleDLinkedList::getCurrentSong() function to get the next song
    
}

void MusicPlayer::previous(){// Moves to the previous song and plays it
    if (playlist.empty()){
        std::cout << type << " has no songs in it." << std::endl;
        return;
    }   
    
    playlist.retreat();
    Song current = playlist.getCurrentSong();
    std::cout << type << " is now playing " << current.getSongTitle() << " by " << current.getSingerName() << std::endl; 
    // calls CircleDLinkedList::retreat() and then the CircleDLinkedList::getCurrentSong() function to get the previous song
}

void MusicPlayer::addSong(const Song& s){// Adds a song before the current song
    //playlist.retreat(); //retreat is called so that the cursor moves to the prior song
    playlist.add(s);//add a song after the current sound.
    // instead of A->D->B->C-> by simply calling add, if i call retreat() it goes to C and then puts D after C 
    //which is before A b/c it is a circularly double linked list. 
}

void MusicPlayer::removeSong(){// Removes the current song
    if (playlist.empty()){
        std::cout << type << " has no songs in it." << std::endl;
        return;
    }  
    
    Song current = playlist.getCurrentSong();//saving current song to current so i can cout information
    
    std::cout << "Removing song " << current.getSongTitle() << " by " << current.getSingerName() << std::endl; //cout removal of song
    
    playlist.remove(); //call CircleDLinkedList::remove() so that i can remove song and decrement n as well as fix next and prev ptr.
}

int MusicPlayer::size() const{// Returns current number of songs
    int numsongs = playlist.size();
    return numsongs;
}

bool MusicPlayer::empty() const{// Checks if the music player is empty
    if (playlist.empty()){
        return true; //if the list is empty it returns true
    }   
    else{//if the list is not empty it returns false 
        return false;
    }
}

Song MusicPlayer::getCurrentSong() const{// Returns the current song
    return playlist.getCurrentSong();
}

void MusicPlayer::print(bool direction){// Prints playlist from current song (true = forward, false = reverse,  recursive) 
                                        //Should be implemented as an recursive function 
    static int size = 0; //total number of songs in the playlist
    static int index = 0; // keeps track of the anount of times the function has been called, helps with base case.
    static bool start = false; //ensures the initialization runs once when called and not everytime in the recursion
    
    if (!start) {//first run through, started is always false at first
    if (playlist.empty()) { // checks if playlist is empty to avoid dereferencing a null ptr. 
        std::cout << type << " playlist is empty." << std::endl;
        return;
        }
        
        size = playlist.size();  // store how many songs on list to print
        index = 0;       //start counting at 0 for the first song
        start = true;   //mark setup as done so truehat it doesn't come back in here.
    }

    if (index >= size) {//base case, if the index is bigger than or equal to the size of the list
        index = 0; //set index back to 0 to better keep track of recursions
        size = 0; // set size back to 0 to accomodate for growth of playlist if there is any
        start = false;  //reset static variables for next time
        return; //this is what stops the recursion and mokes sure the function is be able to terminate
    }
    
    play();
    
    if (direction){
        playlist.advance(); //moves the list or cursor forward if true
    }
    else {
        playlist.retreat(); // moves the list or cursor backward if false 
    }
    
    index++; //increases the index var for the base case implementation
    print(direction); //calls the function again for the next song to be printed (recursion)
    
}
