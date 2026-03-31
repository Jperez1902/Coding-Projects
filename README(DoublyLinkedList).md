Prompt: Develop a C++ application to implement a music player using Object-Oriented 
Programming concepts. Specifically, this will utilize a Doubly Circular Linked 
List. The project involves creating a Song class to represent individual songs, 
a doubly circular linked list to manage the playlist, and a MusicPlayer class 
to control playback operations.

Implementation Explanation:

I was tasked with creating a program that would simulate a form of music player by creating and implementing a double
circular linked list with no dummy nodes. We would have to implement several .h and .cpp files to make this work, .h being the declaration while
the .cpp is the implementation or how the functions work. Namely of course, first is our Song files which will contains the data or 
the what of what we're storing in our double circular linked list. Next we have the DNode files which contains the how, or how we're going to link all of our
song objects. Next we have the CircleDLinkedList files which allows us to control the dnodes and the actual linked list. Implementing functions to add, and remove 
nodes, as well as printing the list. Finally we have the MusicPlayer files which allows the user or whatever code is in our main.cpp to interact with the 
CircleDLinkedList files without breaking encapsulation or accessing it directly. 

- Tool 1: C++ using CodeLabZone (IDE)
- Tool 2: Chat.GPT (Used for assistance in providing guidance and code debugging)
- Tool 3: Youtube Videos (Assistance, and Guidance of Implementation)

## 3. Implementation Details
### Key Components
- [Classes] - Like I mentioned in the introduction, we have a total of 4 classes. We have the Song, DNode, CircleDLinkedList, and MusicPlayer Classes.
    class Song: This contains the data. Declares what we're storing in our double circular linked list, which in this case are strings that represent song titles and their
    respective singer names.
    class DNode: This contains DNode how we're going to link all of our song objects. Since we're working with double circular linked list we have pointers like next and prev,
    as well as the Song var and the constructer which shows that a singular dnode holds a song object, and two pointer, next & prev.
    class CircleDLinkedList: This contains the controls for the linked list using functions such as add(), remove() and print() and allows the user to 
    manipulate the list any way they would like via the next class.
    class MusicPlayer: This class is the final class implemented and contains the functions needed for the user to interact with the controls that the 
    CircleDLinkedList class provides without actually letting them use and come into contact with it as to not break encapsulation. 
    
- Functions: I will list and describe the member functions in the order of which I introduced the classes.

    int DNode::activeNodes = 0;: Define the static variable to keep track how many DNode objects currently exist, initalized at 0.
    //Useful for debugging memory leaks or active node tracking.
    
    DNode(const Song& s, DNode* p, DNode* n): Constructor initalizes node that have the private variables with the parameters passed through initialization 
    essentially elem = s, and next and prev point to n and p respectively. This function also increments the static counter to track the number of active DNode objects.

    ~DNode(): This function is the destructor of DNode. It also decrements the static counter to update the number of active DNode objects and keep track.
    
    
    Song(std::string sTitle, std::string sName): Constructor for the song object, using the two string parameters, it sets it to the private variables songTitle and singerName.
    
    ~Song(): Is a destructor but its empty because there's nothing to destroy, since in C++ std::string aLready deletes or destroys everything automatically.
    
    getSongTitle(): Returns the song title.

    getSingerName(): Returns the singer name

    setSongTitle(std::string songT): Sets the song title by making songTitle = parameter var.
    
    setSingerName(std::string songN): Sets the singer name by making singerName = parameter var.

    ostream& operator<<(std::ostream& os, const Song& song):  Overloads the << operator so that the compiler knows how to print out the song objects. 
    
    
    CircleDLinkedList(): Constructor of CircleDLinkedList objects, sets the cursor pointer to null and the size of node otherwise known as n = 0;

    ~CircleDLinkedList(): Destructor, implements a while loop to check if the object is empty before it destroys it. Then if it is, it uses the remove() function.

    empty() const: One of the most used functions in this entire program, checks if the list is empty, returns true if cursor is nullptr.
    
    size() const: Returns current number of nodes or songs in the list otherwise known as the static int n;
    
    add(const Song& s): Adds a song after the current song, and updates cursor to point to the new song. It does this by creating a new node called newSong with 
    song s parameter in heap then it checks if the this is the first song to be added to the list by calling empty(). If it is the first song or node then you point 
    both the next and prev pointers to itself because it needs to loop as a circular double linked list. After that you move or set the cursor to itself 
    making the new node the current song. If this isn't the first song added to the list meaning empty() is false then you store the node that's currently 
    after cursor or cursor->next in a temporary var. This needed to insert new node between cursor and after. Then you make newSong's next pointer point to the node that comes
    after cursor. Then you make newSong's prev pointer point back to cursor, with you then making cursor's next pointer point to newSong node instead. Then you make the prev 
    ptr of the node that was after cursor point to the newSong which was just added. FINALLY you update the cursor moving it to newSong. Then you increment n or the amount of |
    nodes.
	
    remove(): Removes the current song, and updates cursor to point to next song. To do this you first check if list is empty because if it is we cannot delete 
    anything, if not proceed to making a temporary ptr var called old and make it point to current node which we are going to delete. Then you check if the node points to
    itself, meaning there's only one node. If that is the case then we make cursor = nullptr. If its not the only song then we create a before node and point it to what comes
    before the cursor, as well as create after node and point it to what comes after the cursor. Then we make it so the before node's next ptr points to the after node and the 
    after node's prev ptr points to the before node. Following that we update the cursor to be the after. Finally, we delete the old var and decrement n or number of node by 1;
    
    advance(): Moves to the next song by first checking if the list is not empty. If it is empty we want to avoid dereferencing a nullptr, so the function just returns without
    doing anything. But if the list isn't empty we make the cursor point to the next node, making the next node the current song. 
    
    retreat(): Similarly to the advance() function it first checks if the list is not empty. Then if the list isn't empty we make the cursor point to the prev node, 
    making the prev node the current song.

    getCurrentSong() const: Returns the current song by first checking if the playlist is empty. If it is it throws an exception and says that the list is empty. If the
    list isn't empty then the function simply returns the cursor pointing at the song object.

    print(bool forward) const: Prints all songs in list starting from current position and uses bool parameter to determine whether it prints it out in forward order or reverse
    order. Again we call empty() to avoid dereferencing a nullptr. Once we pass that we create a temporary node and set it to current song or cursor without using actual cursor.
    Following that we use a for loop with i being less than the size of the list, to cout all of the song titles, singer names and a number that shows what number song they are
    on the list. Before the loop ends we check the value of the bool parameter which then sets the temporary cursor node value to point to next or prev. The last line was a 
    design choice for the separation of the lines of text in the output box. 
    

    MusicPlayer(std::string typeplayer): Constructor, takes a string which is the name of the type of music player you want to create. Set private string type = to parameter
    string. 

    ~MusicPlayer(): When this goes out of scope, or the program inputs from main.cpp end C++ calls ~CircleDLinkedList and destroys the object created, nothing is really need in 
    this destructor. This also helps avoid double destruction or the destruction of something that was already destroyed because CircleDLinkedList destroys nodes , and
    string type destroys automatically . I included a sentence output to notify when the object gets destroyed because I'd thought it would be nice to have. 

    play(): Plays the current song and prints the song details. It does this by calling empty() to ensure no dereferencing of nullptr. After this it creats a song object called
    current that it then stores the value for playlist.getCurrentSong() in. Then it couts std::cout << type << " is now playing " << current.getSongTitle() << " by "
    << current.getSingerName() << std::endl;

    next(): Does the same thing as play() function but calls CircleDLinkedList's advance() before storing the data in temporary song object current and printing the
    information. This helps move the cursor to the next song. 

    previous(): Does the same thing as play() function but calls CircleDLinkedList's retreat() before storing the data in temporary song object current and printing the
    information. This helps move the cursor to the previous song. 

    addSong(const Song& s): Adds a song by directly calling add() and passing the song object from the parameter to the function. 

    removeSong(): First calls empty() to ensure no dereferencing of nullptr. If the list is empty, then it just returns. If not it stores the current song data in temporary 
    song object called current, couts information about which song it is removing and then calls the remove() function from CircleDLinkedList. 
    
    size() const: It stores the current list size by creating temporary int variable numsongs and calling the CircleDLinkedList size() function. It then returns numsongs.
    
    empty() const: Checks if the music player is empty, if the list is empty it returns true and if the list is not empty it returns false.
    
    getCurrentSong() const: Returns the current song by calling the getCurrentSong() function. //I didn't make a temporary value to store here cause I realized I really didn't 
    //need to, but was too stubborn to delete any other
   
    print(bool direction): prints the list of songs by calling CircleDLinkedList print() function and passing the boolean parameter into it to determine whether its going to
    print forward or in reverse. It does so recursively by calling itself each time, with the base case being that static int index is bigger than static int size which is the
    size of the list. 


### Design Choices
When I started creating files to further implement the classes and member functions I wasn't paying much attention to syntax in terms of what files I included so when I tried
to run or compile the code it gave me a lot of errors. It took me a bit to clear the errors one by one but it was simple mistakes like including the friend tag when I was 
the opperator << function which was caused by me copy and pasting from the instructions. I also copied the instructions from the Assignment.mk file and commmented it 
out in order to prevent going back and forth between the files. In addition to this the use of comments for me was extremely helpful because it helped me keep track of what
I was doing but also was helping me with explain my design choices behind what I was doing. Like in my MusicPlayer::size() function I created a int variable called 
numsongs and made it equal to playlist.size() which is the playlist var from MusicPlayer calling the size() function from the CircleDLinkedList class. This was merely done
due to personal prefence and doesn't necessarily do anything besides make a copy of playlist.size() but I still included it just cause. But other functions in MusicPlayer like 
the next() and previous() functions call the CircleDLinkedList empty() function to check if the linked list is empty to avoid dereferencing a null ptr and possibly causing a 
crash. Any time empty() is called in the CircleDLinkedList or MusicPlayer functions is for this reason. Regarding words, diction and syntax like std::cout << type << 
" is now playing " << current.getSongTitle() << " by " << current.getSingerName() << std::endl. I did this because when creating multiple CircleDLinkedList playlist objects,
it will cout which object is playing what song. ex: Apple Music is now playing xyz. and Spotify is now playing abc. etc.

Interestingly enough this assignment provided me with even more linked list understanding and helped me visualize the logic behind linked list. There was a typo with the 
MusicPlayer::addSong() function instructions where it requested to add a song before the current song. This stumped me because the corresponding add function from CircleDLinkedList
made it so you added the song after the current song and updated the cursor. But given this experience this typo actually helped me because it allowed me to visualize the options I had to accomplish
this. I ended up going with calling the retreat() function from CircleDLinkedList in order to achieve what the instructions were requesting of me even though it was a typo, and then later fixed it so
it worked as intended when the clarification regarding the typo was cleared up. The application of all four classes seemed like alot of work that I needed to do at first but the understanding of encapsulation
and why the MusicPlayer class and member fuctions were needed helped me with the application of the implementation. 
