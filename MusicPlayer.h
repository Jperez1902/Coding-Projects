//MusicPlayer.h

/*### MusicPlayer Class Implementation
Construct a MusicPlayer class to manage and operate on a collection of Song 
objects using the doubly circular linked list.

#### MusicPlayer.h (Header File)
- Member Variables (Private):
  - std::string type;             // Type of music player
  - CircleDLinkedList playlist;   // Doubly circular linked list of songs

- Member Functions (Public):
  - MusicPlayer(std::string);    // Constructor 
  - virtual ~MusicPlayer();      // Destructor
  - void play();                 // Plays the current song (prints the song 
                                   // details)
  - void next();                 // Moves to the next song and plays it
  - void previous();             // Moves to the previous song and plays it
  - void addSong(const Song&);   // Adds a song after the current song
  - void removeSong();           // Removes the current song
  - int size() const;            // Returns current number of songs
  - bool empty() const;          // Checks if the music player is empty
  - Song getCurrentSong() const;  // Returns the current song
  
    // Prints playlist from current song (true = forward, false = reverse,  recursive)
  - void print(bool);   //Should be implemented as an recursive function*/  
 
#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
  
#include <iostream>
#include "CircleDLinkedList.h"

class MusicPlayer {
    private:
        std::string type;             // Type of music player
        CircleDLinkedList playlist;   // Doubly circular linked list of songs
    public:
         MusicPlayer(std::string);    // Constructor 
         virtual ~MusicPlayer();      // Destructor
         void play();                 // Plays the current song (prints the song details)
         void next();                 // Moves to the next song and plays it
         void previous();             // Moves to the previous song and plays it
         void addSong(const Song&);   // Adds a song before the current song
         void removeSong();           // Removes the current song
         int size() const;            // Returns current number of songs
         bool empty() const;          // Checks if the music player is empty
         Song getCurrentSong() const;  // Returns the current song
         // Prints playlist from current song (true = forward, false = reverse,  recursive)
         void print(bool);   //Should be implemented as an recursive function   
};

#endif