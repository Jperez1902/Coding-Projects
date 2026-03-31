//main.cpp

/*#### Main Function Structure
Initialization:
    - Create an English Dictionary with 10 words and their definitions, including
      repetitions:
      - `{3 definitions, 4 definitions, 1 definition, 2 definitions}`.
    
    Testing Operations:
    - Print the list of all words and definitions starting from the beginning.
    - Print the list of all words and definitions starting from the end.
    - Print the definitions for a word with 2 definitions starting from the 
      beginning of the range.
    - Print the definitions for a word with 2 definitions starting from the end 
      of the range.
    - Remove the first definition of the word with 3 definitions.
    - Search for the word with 4 definitions and print them all.
    - Remove the first definition of the word with 4 definitions.
    - Remove all definitions for the word with 2 definitions.
    - Print the list of all words and definitions starting from the beginning.
    - Print the list of all words and definitions starting from the end.*/
    
#include "EnglishDictionary.h"
#include "DNodeG.h"
#include <string>
#include <iostream>


                            
int main(){
    
    EnglishDictionary Oxford("Oxford Dictionary");
    
    //one word one definition
    Oxford.add("LOL", "An acronym that stands for 'Laughing Out Loud'.");
    Oxford.add("LOL", "'Laughing Out Loud' or another way to express laughter in online social spaces and common message slang.");
    //one word two definitions
    Oxford.add("Ragebait", "To enrage someone or cause frustration by saying something outrageous.");
    Oxford.add("Ragebait", "To make someone angry.");
    //one word three definitions
    Oxford.add("Aurafarm", "To try to increase one's social cool points by acting nonchalant and unbothered.");
    Oxford.add("Aurafarm", "To raise ones aura.");
    Oxford.add("Aurafarm", "Piccolo.");
    //one word four definitions
    Oxford.add("Bank", "To tilt an aircraft while turning (verb).");
    Oxford.add("Bank", "A financial instituion that handles legal tender.");
    Oxford.add("Bank", "The side of a river or body of water..");
    Oxford.add("Bank", "A row or series of something, such as a bank of elevators.");
    
    //Print the entire dictionary (forward)
    std::cout << "=== Full Dictionary (Forwards) ===" << std::endl;
    Oxford.printDictionary(true);
    std::cout << std::endl;
    //Print the entire dictionary (backwards)
    std::cout << "=== Full Dictionary (Backwards) ===" << std::endl;
    Oxford.printDictionary(false);
    
   //Print definitions for a word with 2 definitions (forward) ---
    std::cout << "\n=== Definitions for 'Ragebait' (Forward) ===" << std::endl;
    Oxford.printWord("Ragebait",true);
    std::cout << std::endl;
    //Print definitions for a word with 2 definitions (backward) ---
    std::cout << "\n=== Definitions for 'Ragebait' (Backward) ===" << std::endl;
    Oxford.printWord("Ragebait",false);
    std::cout << std::endl;
    //Remove first definition of the word with 3 definitions ---
    Oxford.deleteFirst("Aurafarm");
    //Search for word with 4 definitions and print all ---
    std::cout << "\n=== Definitions for 'Bank' ===" << std::endl;
    Oxford.printWord("Bank");

    //Remove first definition of the word with 4 definitions ---
    Oxford.deleteFirst("Bank");

    //Remove all definitions for the word with 2 definitions ---
    Oxford.deleteWord("Ragebait");

    //Print all words/definitions (forward) ---
    std::cout << "\n=== Full Dictionary (Forward) After Deletions ===" << std::endl;
    Oxford.printDictionary(true);

    //Print all words/definitions (backward) ---
    std::cout << "\n=== Full Dictionary (Backward) After Deletions ===" << std::endl;
    Oxford.printDictionary(false);
    
    return 0;
}


