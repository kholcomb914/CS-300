/**
 * @file vigenere.cpp
 * @author Kaustubh Holcomb (holcombk@uab.edu)
 * @brief Implementation for the Vignere class.
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "vigenere.h"

Vigenere::Vigenere(std::string cKey) {
    key = cKey;
}

Vigenere::~Vigenere() {}

std::string Vigenere::encrypt(std::string msg) {
    std::string encrypted;
    for(int i = 0; i < msg.size(); i++) {
        auto start = std::find(letters.begin(), letters.end(), msg[i]);
        auto add = std::find(letters.begin(), letters.end(), key[i%3]) + 1;
        char push = letters[(((start - letters.begin()) + (add - letters.begin())) % 26) - 1];
        encrypted.push_back(push);
    }
    return encrypted;
}

std::string Vigenere::decrypt(std::string msg) {
    int first = 26 - (std::find(letters.begin(), letters.end(), key[0]) - letters.begin());
    int second = 26 - (std::find(letters.begin(), letters.end(), key[1]) - letters.begin());
    int third = 26 - (std::find(letters.begin(), letters.end(), key[2]) - letters.begin());
    std::string tempKey = "";
    tempKey += letters[first];
    tempKey += letters[second];
    tempKey += letters[third];
    // yes, I know this is a really stupid way to solve this but I had a huge headache when I was working on it
    std::string oldKey = key;
    key = tempKey;
    std::string dec = encrypt(msg);
    key = oldKey;
    return dec;
}

bool Vigenere::isEncrypted(std::string encryptedMsg, std::string decryptedMsg) {
    return (decrypt(encryptedMsg).compare(decryptedMsg) == 0);
}

void Vigenere::setKey(std::string cKey) {
    key = cKey;
}

std::string Vigenere::getKey() {
    return key;
}
