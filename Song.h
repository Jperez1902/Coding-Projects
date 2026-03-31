//Song.h

/*#### Song.h (Header File)
- Member Variables (Private):
  - std::string songTitle;   // The title of the song
  - std::string singerName;  // The name of the singer

- Member Functions (Public):
  - Song(std::string sTitle = "", std::string sName = ""); // Constructor
                                      
  - ~Song();                        // Destructor
  - std::string getSongTitle();      // Returns the song title
  - std::string getSingerName();     // Returns the singer name
  - void setSongTitle(std::string);  // Sets the song title
  - void setSingerName(std::string); // Sets the singer name
  
    // Overload << operator to print Song objects
  - friend std::ostream& operator<<(std::ostream& os, const Song& song);*/
  
#ifndef SONG_H
#define SONG_H

#include <iostream>

 
class Song {
  private:
    std::string songTitle;   // The title of the song
    std::string singerName;  // The name of the singer
  
  public:
    Song(std::string sTitle = "", std::string sName = ""); // Constructor
    ~Song();                        // Destructor
    std::string getSongTitle();      // Returns the song title
    std::string getSingerName();     // Returns the singer name
    void setSongTitle(std::string);  // Sets the song title
    void setSingerName(std::string); // Sets the singer name
  
    // Overload << operator to print Song objects
    friend std::ostream& operator<<(std::ostream& os, const Song& song);
    
};

#endif