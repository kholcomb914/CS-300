BUILD PROJECT:
1  To build the project, first make sure the input text file containing the Hamming (7,4) code words is contained within the project directory.
2  Clone both the eigen and google test framework libraries into the project folder:
    >> git clone https://gitlab.com/libeigen/eigen.git
    >> git clone https://github.com/google/googletest.git 
3  Navigate to the directory in the command line, and create the build directory to navigate to:
    >> mkdir build
    >> cd build
4  Run cmake in the top level directory:
    >> cmake ..
5  Build the project files:
    >> make

RUN UNIT TESTS:
1  While in the build folder, run ctest:
    >> ctest
2  If detailed test results do not appear in the command line output, they are likely located at build/Testing/Temporary/LastTest.log
3  The rubric obviously stated that I had to include 15 unit tests, but this was quite impossible, given that I only have five functions to test in my hamming.cpp file.

RUN PROGRAM:
1  Run the program with ./main, using the name of the input file as the second argument.
   For example, if the input file is named inputValues.txt and is contained in the project folder above the build directory:
    >> ./main ../inputValues.txt
2  And the program will decode the code words and print the corrected words, as well as if there are any errors.

DOCUMENTATION:
1  All documentation is covered by doxygen and contained within the html folder.

MAKEFILE:
1  The makefile included in the repository will allow you to build the project:
    >> make
2  And run the program similarly to the cmake method above:
    >> ./main inputValues.txt
3  But it does not allow for unit testing, so it is recommended to build with cmake instead. The makefile was only included within the repo because it was required on the rubric.

WRITE-UP:
1  This project was done entirely by me, with no assistance from a partner.
2  This project was done entirely by me, with no assistance from a partner.
3  My biggest takeaway from this course is that computer science is far less about being able to write clean, error-free code on your first attempt, and far more about being able to use the tools at your disposal adequately to be able to diagnose and rectify the errors that will invariably occur.
4  My biggest gripe about this class was the overreliance on makefile and lack of time spent covering cmake. The final project expected us to create unit tests for our project (though not specicially with Google Test, we were basically forced to do so because that was the only unit test framework we spent any time covering), which effectively forced me to use cmake in order to get the tests to integrate properly and not just be function bodies sitting in a cpp file. However, this was made far more difficult due to the fact that zero time was spent teaching us even the slightest thing about cmake. As a result, probably less than ten percent of my time on the final project was actually spent on the problem itself, with the remaining ninety percent being dedicated to teaching myself the basics of cmake so I could actually try to fulfill the project requirements.
