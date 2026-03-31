//main.cpp

/*#### Main Function Structure
- **Initialization**: 
  - Create a MusicPlayer instance initialized 
  - Add 3 songs 

- **Initial Playback**: 
  - Play Current Song: Start by playing the current song (call play()) in the playlist.
  - Next Songs Playback: Play the next song three times (call next() three times), 
    showing ability to move forward in the playlist.
  - Previous Song Playback: Play the previous song (call previous()), showing ability to 
    navigate backward.

- **Playlist Review**: 
  - Print Forward: Use the print(true) method to list all songs from the 
    current position forward.
  - Print Reverse: Use the print(false) method to list all songs in reverse 
    order, demonstrating the doubly circular list's bidirectional traversal.

- **Modifying the Playlist**:
  - Remove Current Song: Remove the song currently being played (call removeSong())
    from the playlist.
  - After removal, continue playback to show how the list updates:
    - Play Current Song: Play the new current song (call play()) in the playlist.
    - Next Songs Playback: Play the next song three times (call next() three times)
      to show how the playlist works after removal.

- **Final Playlist Review**: 
  - Final Print Forward: Use the print(true) method to display the updated 
    list of songs from the current position forward.
  - Final Print Reverse: Use the print(false) method to display the songs in 
    reverse order, showing the final playlist state.
*/

#include <iostream>
#include "MusicPlayer.h"
#include "Song.h"
#include "CircleDLinkedList.h"

int DNode::activeNodes = 0; // Define the static variable to keep track how many DNode objects currently exist, initalized at 0
                            //Useful for debugging memory leaks or active node tracking.
    
int main(){
    
    
    //Initialization
    MusicPlayer skateplaylist("Apple Music");
    skateplaylist.addSong(Song("St. Chroma", "Tyler, The Creator"));
    skateplaylist.addSong(Song("Can I Kick It?", "A Tribe Called Quest"));
    skateplaylist.addSong(Song("ADHD", "Kendrick Lamar"));
    //skateplaylist.addSong(Song("Ring Ring Ring", "Tyler, The Creator"));
    
    //Initial Playback
    skateplaylist.play();
    skateplaylist.next();
    skateplaylist.next();
    skateplaylist.next();
    skateplaylist.previous();
    //skateplaylist.next();
    std::cout << std::endl;
    
    //Playlist Review
    skateplaylist.print(true);
    std::cout << std::endl;
    skateplaylist.print(false);
    std::cout << std::endl;
    
    //Modifying the Playlist
    skateplaylist.removeSong();
    std::cout << std::endl;
    skateplaylist.play();
    skateplaylist.next();
    skateplaylist.next();
    skateplaylist.next();
    std::cout << std::endl;
    
    //Final Playlist Review
    skateplaylist.print(true);
    std::cout << std::endl;
    //skateplaylist.addSong(Song("Ring Ring Ring", "Tyler, The Creator"));
    skateplaylist.print(false);
    
    return 0;
    
    
}

