//Song.cpp

#include <iostream>
#include "Song.h"

 
Song::Song(std::string sTitle , std::string sName ){// Constructor
    songTitle = sTitle; 
    singerName = sName; 
} 

 
Song::~Song(){// Destructor
    //nothing to destroy, in C++ std::string aLready deletes or destroys everything automatically
} 

 
std::string Song::getSongTitle(){// Returns the song title
    return songTitle;
}      

    
std::string Song::getSingerName(){ // Returns the singer name
    return singerName;
}    

 
void Song::setSongTitle(std::string songT){// Sets the song title
    songTitle = songT;
}  

     
void Song::setSingerName(std::string songN){// Sets the singer name
    singerName = songN; 
}

std::ostream& operator<<(std::ostream& os, const Song& song){
    os << "\"" << song.songTitle << "\" by " << song.singerName;
    return os;
}
