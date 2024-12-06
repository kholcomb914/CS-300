/**
 * @file hamming.cpp
 * @author Kaustubh Holcomb (holcombk@uab.edu)
 * @brief Contains implementation of all functions for the Hamming class.
 * @version 0.1
 * @date 2024-11-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "hamming.hpp"

Hamming::Hamming(std::string word)
{
    codeWord << word[0] - '0', word[1] - '0', word[2] - '0', word[3] - '0', word[4] - '0', word[5] - '0', word[6] - '0';
}

Hamming::~Hamming() {
    codeWord.resize(codeWord.rows(), codeWord.cols());
}

Eigen::Matrix<int, 7, 1> Hamming::getCodeWord() {
    return codeWord;
}

void Hamming::flipBit(int index) {
    if(codeWord[index] == 0) {
        codeWord[index] = 1;
    } else {
        codeWord[index] = 0;
    }
}

Eigen::Matrix<int, 3, 1> Hamming::getSyndrome() {
    Eigen::Matrix<int, 3, 1> syndrome = checkMatrix * codeWord;
    for(int i = 0; i < syndrome.size(); i++) {
        syndrome[i] = syndrome[i] % 2;
    }
    return syndrome;
}

int Hamming::decode() {
    Eigen::Matrix<int, 3, 1> syndrome = getSyndrome();
    for(int i = 0; i < codeWord.size(); i++) {
        if(syndrome.isApprox(checkMatrix.col(i))) {
            return i;
        }
    }
    return -1;
}

void Hamming::errorReport()
{
    int errorIndex = decode();
    for(int i = 0; i < codeWord.size(); i++) {
        std::cout << codeWord[i];
    }
    if(errorIndex >= 0) {
        flipBit(errorIndex);
        std::cout << " (Error found at bit " << errorIndex + 1 << ".)" << std::endl;
    } else {
        std::cout << " (No errors found.)" << std::endl;
    }
}
