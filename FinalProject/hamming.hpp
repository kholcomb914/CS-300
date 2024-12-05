/**
 * @file hamming.hpp
 * @author Kaustubh Holcomb (holcombk@uab.edu)
 * @brief Contains all member functions and variables for the Hamming class.
 * @version 0.1
 * @date 2024-11-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef hamming_hpp
#define hamming_hpp

#include <stdio.h>
#include <iostream>
#include "Eigen/Dense"
#include <string>

/**
 * @brief Class contains all functionality to decode a 7-digit Hamming (7,4) code word and detect single errors.
 * 
 */
class Hamming {
public:
    /// @brief Matrix used via multiplication to check the correctedness of the input code word.
    const Eigen::Matrix<int, 3, 7> checkMatrix {
        {1,0,0,0,1,1,1},
        {0,1,0,1,0,1,1},
        {0,0,1,1,1,0,1}
    };

    /**
     * @brief Construct a new Hamming object.
     * 
     * @param word A std::string object that serves as the text input for the code word. 
     */
    Hamming(std::string word);

    /**
     * @brief Destroy the Hamming object
     * 
     */
    ~Hamming();

    /**
     * @brief Calculate and get the column "syndrome" vector that is used to identify the location of the error in the code word, if any.
     * 
     * @return Eigen::Matrix<int, 3, 1> 
     */
    Eigen::Matrix<int, 3, 1> getSyndrome();

    /**
     * @brief Get the codeWord object from the class.
     * 
     * @return Eigen::Matrix<int, 7, 1> 
     */
    Eigen::Matrix<int, 7, 1> getCodeWord();

    /**
     * @brief Flips the bit at a given index from 0 to 1 or vice versa.
     * 
     * @param index The index of the bit that is to be flipped.
     */
    void flipBit(int index);

    /**
     * @brief Decodes the given code word, returning the int index of where the error is found; returns -1 if no error found.
     * 
     * @return int
     */
    int decode();

    /**
     * @brief Uses the rest of the functions in Hamming to produce a text error report for the code word, consisting of the corrected code word and where the error was found, if it exists.
     * 
     */
    void errorReport();
    
private:
    /**
     * @brief Contains the 7-bit Hamming code word, contained in an Eigen column vector.
     * 
     */
    Eigen::Matrix<int, 7, 1> codeWord;
};

#endif /* hamming_hpp */
