INSTRUCTIONS TO RUN PROJECT:
 - Download folder as .zip
 - Unzip folder
 - Navigate to folder in command line
 - enter "make" to compile
 - enter "./a.out" to run
 
 Inheritance was utilized by creating a base class Event and then using two subclasses Conference and Concert to include methods and variables only used by those specific classes.
 A vector of pointers to each event was used because by modifying the pointer within the vector, we modify the event itself, removing the need to access the event object.
 Design patterns are beneficial for much the same reason that inheritance is useful--by allowing for reuse of code and giving our programs maximum flexibility and usability.
 Most of the challenges I encountered during development were with the factory/strategy patterns, because it was my first time implementing them in a program and it was a little challenging to make them work.  I'm still not entirely sure that I did it right, but the project seems to work, so there's that.
