Prompt: Develop a C++ application to implement an English Dictionary using Object-Oriented
Programming (OOP) principles. Requires the implementation of the 
Dictionary ADT using templates and an EnglishDictionary class,
which will utilize an object of the concrete implementation of the Dictionary ADT
as a data structure to store words and definitions and perform operations on them.

Implementation Explanation: 

I was tasked with creating a program that would simulate or resemble an English Dictionary using C++, Object-Oriented programming, Dictionary ADT, a doubly linked list
container, and iterators. I was also instructed to use templates and create an EnglishDictionary class, which will utilize an object of the concrete implementation 
of the Dictionary ADT as a data structure to store words and definitions and perform operations on them.
 
- Tool 1: C++ using CodeLabZone (IDE)
- Tool 2: Chat.GPT (Used for assistance in providing guidance and code debugging)
- Tool 3: Google Gemini (Used for assistance in providing guidance and code debugging)

- [Classes] - In order to make this work, I needed to implement a number of classes that would manipulate the doubly linked list as well as create objects
for the dictionary and other classes like entry to establish the key and value pairs. In total I have 6 classes. We have the Entry, DNodeG, IteratorG, Range
NodeDictionaryG, and finally the EnglishDictionary class(es).

    class Entry: This contains the back bone of the program and is what makes it a dictionary instead of a plain old doubly linked list.
    data. This class defines a generic, templated key-value pair container. It holds one key (K) and one value (V).
	
    class DNodeG: This contains DNodeG which how we're going to link all of our dictionary nodes. This class has the nodes for a doubly linked list.
    Each node holds an Entry<K, V> object called elem and two pointers to the next and prev nodes in the sequence. 
    It also includes a static counter (activeNodes) for tracking memory usage. 
	
    class IteratorG: Gives you an iterator or pointer which allows you to traverse the list element by element and with outside code using simple operations like ++ and --,
    (operator overloading). 
	
    class Range: Allows for the various Range functions needed to implement the Dictionary ADT successfully. The class holds two IteratorG objects which includes one 
    marking the beginning of the range and another one marking the position that comes right after the end of the range.
	
    class NodeDictionaryG: This contains the controls for the linked list using functions such as put(), erase() and print() and allows the user to 
    manipulate the list any way they would like via the next class
	
    class EnglishDictionary: This class is the final class implemented and contains the functions needed for the user to interact with the controls that the 
    NodeDictionaryG class provides without actually letting them use and come into contact with it as to not break encapsulation. 
    
- Functions: I will list and describe the member functions in the order of which I introduced the classes
    
    Entry(const K& k, const V& v): Constructor to initialize an entry with a key (k) and value (v).
    
    ~Entry(): Destructor to release resources.
    
    const K& getK() const: Returns a read-only reference to the key.
    
    const V& getV() const: Returns a read-only reference to the value.
    
    void setK(const K& k): Sets the key to a new value k.
    
    void setV(const V& v): Sets the value to a new value v.
    ____
    DNodeG(...): Constructor to initialize a node with an entry e, prev pointer p, and next pointer n. The creation of a node also increments the static activeNodes counter.
    
    ~DNodeG(): Destructor to decrement the static activeNodes counter when a node is destroyed.
    
    static int activeNodes: A static counter variable used to track the number of nodes currently in existence (useful for debugging memory leaks).
    ____
    IteratorG(DNodeG<K,V>* v): Constructor to initialize the iterator, pointing to a specific node (v).
    
    const Entry<K,V>& entry() const: Returns a read-only reference to the current key–value pair.
    
    const K& getK() const: Getter for the key of the current node's entry.
    
    const V& getV() const: Getter for the value of the current node's entry.

    const V& operator*(): Returns a reference to the value of the current node's entry via operator overloading.

    bool operator==(const IteratorG& p) const: Compares the current iterator with another for equality via operator overloading.

    bool operator!=(const IteratorG& p) const: Compares the current iterator with another for inequality via operator overloading.

    IteratorG& operator++(): Moves the iterator to the next position in the list using ++ via operator overloading.

    IteratorG& operator--(): Moves the iterator to the previous position in the list using -- via operator overloading.
    ___
    Range(const IteratorG& _beg, const IteratorG& _end): Constructor to initialize the range with a beginning iterator and an end iterator.

    const IteratorG& getB() const: Returns a constant reference to the beginning iterator.

    const IteratorG& getE() const: Returns a constant reference to the end iterator.
    ___
    NodeDictionaryG(): Initializes the dictionary, sets up sentinel nodes, and sets counters uniquekeys and n to 0.

    ~NodeDictionaryG(): Deletes all nodes in the list by calling erase(begin()), then deletes the header and trailer nodes.

    int size() const: Returns the total number of entries or n in the dictionary.

    int uniqueKeys() const: Returns the number of unique keys (different words) in the dictionary.

    bool empty() const: Checks if the dictionary is empty, returns true if it is, false if it isn't.

    IteratorG begin() const: Returns an iterator pointing to the first entry which is the node after the header.

    IteratorG end() const: Returns an iterator pointing past the last entry which is the trailer.

    IteratorG find(const K& k) const: Finds and returns an iterator pointing to the first entry with the given key k, or end() if that specific key is not found.

    Range findAll(const K& k): Finds all consecutive entries with the given key k and returns a Range object for them wher b is the first entry with the key and e is the entry
    after the last entry with the key k.

    IteratorG put(const K& k, const V& v): Inserts a key-value pair into the doubly linked list. If the key exists, it inserts the new entry after the last existing entry
    for that key. Updates uKeys if a new unique key is added.

    void erase(const K& k): Removes the first entry found with the given key k, does this by calling the erase by iterator position function.

    void erase(const IteratorG& p): Removes the specific entry at the given iterator position p and updates size as well as the unique key counter if that key has no other
    entries.

    void erase(const Range& r): Removes all entries within the specified range r by obtaining the first entry with key k and the last entry with key k and
    calling erase(iterator) for each entry in between.

    void print():Prints all entries in the dictionary from beginning to end.

    void print(const Range& r, bool forward = true) const: Prints all entries within the specified range r, using the boolean forward  to determine the direction of iteration.
    Forward is true by default which means it prints forwards by default. 
    ___
    EnglishDictionary(const string& n): Constructor: Initializes the dictionary and sets its name (n).

    ~EnglishDictionary(): Empty, as NodeDictionaryG deals with the destruction.

    int words() const: Returns the total number of definitions or entries in the dictionary.

    int uniqueWords() const: Returns the count of unique words or keys in the dictionary.

    bool empty() const: Checks if the dictionary contains any entries. Returns true if empty and false if not. 

    void add(const string& w, const string& d): Adds a new word w and its definition d using the put() function from NodeDictionaryG.

    void deleteFirst(const string& d): Deletes the first definition found for the word d using the erase(const K& k) function from NodeDictionaryG.

    void deleteWord(const string& w): Deletes all definitions for the word w, essentially removing all the definitions from the list. Uses erase(range) from NodeDictionaryG.

    void printDictionary(bool forward, ...): Recursively prints all entries in the entire dictionary. Forward boolean determines the direction, if true it goes forward and
    if false it prints backwards.

    void printWord(const string& w, bool direction = true): Prints all definitions for a given word w. It also uses the boolean direction to determine if it prints forwards 
    or backwards.

    Entry<string, string> find(string w): Finds the first entry for a given word w and returns a copy of that entry.

When it comes to the design choices that I made, one thing I decided to change for readability reasons is the name of the temporary variable that I used whenever I was dealing
with an iterator. Instead of using the basic it variable name, I made my variable names p for position. This helped me with reading and understanding the code. That also goes 
for whenever I was dealing with range where I named the variable that represented the first entry with key k as b and the the variable that represented the node after the last
entry with key k with e. The one exception to the naming scheme that I had with Iterator objects being p is when I was dealing with printDictionary function in 
EnglishDictionary and it made sense to have the Iterator variable be it. Other than that something else I also changed was the printDictionary function name for the range 
version of printDictionary. For some reason the compiler was having issues with distinguishing which function to call which led to the entire list being printed out whenever
I had to print out a word that only had two definitions. To avoid that and make the code less confusing and better to read I named the function that took the range as a
parameter printWord because that's essentially what it is. It prints a word and all of it's definitions. In addition to that change declaring some parameters and variables as
const helped solve the solution of well. 

- Common Errors Encountered:
  - Error 1: Each node I made had a value of 0.
    - Cause: I made the DNodeG constructor elem() which made each node I made blank instead of the value I assigned to it. This meant that the value that was being passed 
    through as a parameter wasn't being assigned to the Entry<K,V> elem
    - Solution: I realized I made the mistake and corrected it so instead of 0 it had elem(i) which was the actual parameter I had for the dnode constructor.
  
  - Error 2: Range kept going out of the given key
    - Cause: Every time I tried to only print out one word and it's definitions the entire list was being printed. 
    - Solution: Changing the name of the printDictionary function to printWord and applying const to the range and iterator function allowed me to use them without modifying 
    them. 
    
## 5. Testing Strategy
Going through the logic of each add and erase function on paper allowed me to test the logic of my functions without actually having to run the code. Of course when I did
feel as I was ready and got the program to compile, testing all of the required functions also allowed me to check what was and wasn't working properly. Also differentiating
the different types of outputs in the main function allowed me to pinpoint what was going wrong and what was working. 

## 6. Conclusion
The implementation of the Dictionary ADT through the use of the doubly linked list container has allowed me to better understand the Dictionary ADT as a whole. It also made 
the relationship between Iterator, DNode and DictionaryList clearer to me. If there was anything I would like to do it would be the implementation of the Hash Table through
the use of Hash Code and the Hash Function. Perhaps creating a bucket array as well so that I can access words with multiple definitions in costant time O(1). 
