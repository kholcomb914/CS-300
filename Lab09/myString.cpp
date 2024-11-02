//
//  myString.cpp
//  Lab09
//
//  Created by Kaustubh on 10/29/24.
//
#include "myString.hpp"

MyString::MyString(std::string inputString) {
    for(int i = 0; i < inputString.size(); i++) {
        charVector.push_back(inputString[i]);
    }
}
MyString::~MyString() {
    charVector.clear();
}

std::string MyString::toString() {
    std::string output;
    for(char letter : charVector) {
        output += letter;
    }
    return output;
}

int MyString::length() {
    return charVector.size();
}

std::string MyString::substr(int start) {
    std::string output;
    for(int i = start; i < charVector.size(); i++) {
        output += charVector[i];
    }
    return output;
}

std::string MyString::substr(int start, int n) {
    std::string output;
    for(int i = start; i <= n; i++) {
        output += charVector[i];
    }
    return output;
}

std::vector<char> MyString::getCharVector() {
    return charVector;
}

MyString operator+(const MyString& add) {
    MyString newMyString = MyString();
    for(char letter : add.charVector) {
        newMyString.charVector.push_back(letter);
    }
    return newMyString;
}

std::ostream& operator<<(std::ostream& os, const MyString& out) {
    std::string printOut;
    for(char letter : out.charVector) {
        printOut += letter;
    }
    os << printOut;
    return os;
}

bool MyString::operator==(const MyString& compare) const {
    return charVector == compare.charVector;
}

bool MyString::operator!=(const MyString& compare) const {
    return charVector != compare.charVector;
}

bool MyString::operator<=(const MyString& compare) const {
    bool out = true;
    for(int i = 0; i < charVector.size(); i++) {
        if(charVector[i] < compare.charVector[i]) return true;
        else if(charVector[i] > compare.charVector[i]) return false;
    }
    return out;
}

bool MyString::operator>=(const MyString& compare) const {
    bool out = true;
    for(int i = 0; i < compare.charVector.size(); i++) {
        if(charVector[i] < compare.charVector[i]) return false;
        else if(charVector[i] > compare.charVector[i]) return true;
    }
    return out;
}

bool MyString::operator<(const MyString& compare) const {
    bool out = false;
    for(int i = 0; i < charVector.size(); i++) {
        if(charVector[i] < compare.charVector[i]) return true;
        else if(charVector[i] > compare.charVector[i]) return false;
    }
    return out;
}

bool MyString::operator>(const MyString& compare) const {
    bool out = false;
    for(int i = 0; i < compare.charVector.size(); i++) {
        if(charVector[i] < compare.charVector[i]) return false;
        else if(charVector[i] > compare.charVector[i]) return true;
    }
    return out;
}





